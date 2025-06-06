#include <iostream>

using namespace std;

// Abstract Product A
class AbstractProductA {
public:
    virtual void display() = 0;
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void display() = 0;
};

// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void display() override 
    {
        cout << "Product A1\n";
    }
};

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void display() override
    { 
        cout << "Product A2\n";
    }
};

// Concrete Product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void display() override
    {
        cout << "Product B1\n";
    }
};

// Concrete Product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void display() override 
    {
        cout << "Product B2\n";
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override { return new ConcreteProductA1(); }
    AbstractProductB* createProductB() override { return new ConcreteProductB1(); }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override { return new ConcreteProductA2(); }
    AbstractProductB* createProductB() override { return new ConcreteProductB2(); }
};

int main() {
    AbstractFactory* factory = new ConcreteFactory1();
    AbstractProductA* productA = factory->createProductA();
    AbstractProductB* productB = factory->createProductB();

    productA->display();
    productB->display();

    delete productA;
    delete productB;
    delete factory;

    return 0;
}
