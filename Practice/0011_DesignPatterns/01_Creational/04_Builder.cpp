/*
🔹 What is Builder Design Pattern? 🔹
===================================================================
Builder lets you construct complex objects step by step.
It separates the algorithm for object creation from its representation.
This allows you to reuse the algorithm to create different representations of the object.

🔹 C++ Example 🔹
==========================
Let's say we want to construct a Car with various components (engine, seats, GPS...).
Instead of putting all this into a huge constructor, we use Builder.

*/

#include <iostream>
using namespace std;

// Product - Car
// This is the complex object we want to construct.
class Car {
private:
    string engine;
    int seats;
    bool gps;

public:
    void setEngine(const string& engine) {
        this->engine = engine;
    }

    void setSeats(int seats) {
        this->seats = seats;
    }

    void setGPS(bool gps) {
        this->gps = gps;
    }

    void showCarDetails() {
        cout << "Car details:" << endl;
        cout << "Engine: " << engine << endl;
        cout << "Seats: " << seats << endl;
        cout << "GPS: " << (gps ? "Yes" : "No") << endl;
    }
};


// Builder Interface
// Declares methods for building the car step by step.
class CarBuilder {
public:
    virtual void buildEngine() = 0;
    virtual void buildSeats() = 0;
    virtual void buildGPS() = 0;
    virtual Car* getCar() = 0;

    virtual ~CarBuilder() = default;
};


// Concrete Builder 1 - Sport Car
class SportCarBuilder : public CarBuilder {
private:
    Car* car;

public:
    SportCarBuilder() {
        car = new Car();
    }

    void buildEngine() override {
        car->setEngine("V8 Sport Engine");

    }

    void buildSeats() override {
        car->setSeats(2);
    }

    void buildGPS() override {
        car->setGPS(true);
    }

    Car* getCar() override {
        return car;
    }
};


// Concrete Builder 2 - Family Car
class FamilyCarBuilder : public CarBuilder {
private:
    Car* car;

public:
    FamilyCarBuilder() {
        car = new Car();
    }

    void buildEngine() override {
        car->setEngine("V4 Family Engine");

    }

    void buildSeats() override {
        car->setSeats(5);
    }

    void buildGPS() override {
        car->setGPS(false);
    }

    Car* getCar() override {
        return car;
    }
};


// Director
// Orchestrates the building process.
class Director {
private:
    CarBuilder* builder;

public:
    void setBuilder(CarBuilder* builder) {
        this->builder = builder;
    }

    void constructCar() {
        builder->buildEngine();
        builder->buildSeats();
        builder->buildGPS();
    }
};


int main()
{
    Director director;

    // Build Sport Car
    SportCarBuilder sportBuilder;
    director.setBuilder(&sportBuilder);
    director.constructCar();

    Car* sportCar = sportBuilder.getCar();
    sportCar->showCarDetails();

    delete sportCar;

    cout << endl;

    // Build Family Car
    FamilyCarBuilder familyBuilder;
    director.setBuilder(&familyBuilder);
    director.constructCar();

    Car* familyCar = familyBuilder.getCar();
    familyCar->showCarDetails();

    delete familyCar;

    return 0;
}

/*
output
===================================
Car details:
Engine: V8 Sport Engine
Seats: 2
GPS: Yes

Car details:
Engine: V4 Family Engine
Seats: 5
GPS: No



🔹 Summary 🔹
==========================================================
✅ Builder lets you construct complex objects step by step.
✅ Separates algorithm from representation — it's easy to create different variants of an object.
✅ Helps make code more flexible and easier to maintain or extend.



*/
