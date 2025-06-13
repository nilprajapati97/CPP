/*
🔹 What is Factory Method? 🔹
===========================================
Factory Method lets you create object instances without specifying their exact class.
Instead of instantiating directly with new ConcreteClass(), you call a factory method —
this lets subclasses decide which class to create.
*/

#include <iostream>
using namespace std;

// Product base class
class Product {
public:
    virtual void use() = 0;
    virtual ~Product() = default;
};


// Concrete Product: Car
class Car : public Product {
public:
    void use() override {
        cout << "Using a Car!" << endl;
    }
};


// Concrete Product: Bike
class Bike : public Product {
public:
    void use() override {
        cout << "Using a Bike!" << endl;
    }
};


// Base factory
class Factory {
public:
    virtual Product* createProduct() = 0;
    virtual ~Factory() = default;
};


// Car factory
class CarFactory : public Factory {
public:
    Product* createProduct() override {
        return new Car();
    }
};


// Bike factory
class BikeFactory : public Factory {
public:
    Product* createProduct() override {
        return new Bike();
    }
};


int main()
{
    // Create a Car using CarFactory
    Factory* carFactory = new CarFactory();
    Product* car = carFactory->createProduct();
    car->use();

    // Create a Bike using BikeFactory
    Factory* bikeFactory = new BikeFactory();
    Product* bike = bikeFactory->createProduct();
    bike->use();

    // Clean up
    delete carFactory;
    delete bikeFactory;
    delete car;
    delete bike;

    return 0;
}

/*

    Output
    ===============
    Using a Car! 
    Using a Bike! 

    🔹 Summary 🔹
✅ Factory Method lets you create objects without specifying their exact class.
✅ Provides a way to enable subclasses to determine which object to create.
✅ Helps promote code reuse and follow the Open/Close Principle (open for extension, closed for modification).

*/