/*
03. Decorator Pattern
============================================================
🔸Use Case: Add optional features to a base component
Example: A basic coffee, with optional milk, sugar, etc.

*/


#include <iostream>
using namespace std;

class Coffee {
public:
    virtual string description() = 0;
    virtual int cost() = 0;
};

class BasicCoffee : public Coffee {
public:
    string description() override { return "Coffee"; }
    int cost() override { return 5; }
};

class MilkDecorator : public Coffee {
    Coffee* base;
public:
    MilkDecorator(Coffee* c) : base(c) {}
    string description() override { return base->description() + " + Milk"; }
    int cost() override { return base->cost() + 2; }
};

class SugarDecorator : public Coffee {
    Coffee* base;
public:
    SugarDecorator(Coffee* c) : base(c) {}
    string description() override { return base->description() + " + Sugar"; }
    int cost() override { return base->cost() + 1; }
};

int main() {
    Coffee* c = new BasicCoffee();
    c = new MilkDecorator(c);
    c = new SugarDecorator(c);

    cout << c->description() << " | Cost: $" << c->cost() << endl;
}

