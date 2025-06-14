/*
🔹 What is Prototype Design Pattern? 🔹
===================================================================
Prototype lets you create new object instances by copying or cloning an existing object instead of instantiating from scratch.
This is especially useful when object creation is heavy or complex, or when you want to produce many copies with slight variations.

🔹 C++ Example 🔹
========================================
Let's say we have a base class Shape with a clone method.
We can create copies without needing to construct them directly.

*/


#include <iostream>
using namespace std;

// Base class with clone method
class Shape {
protected:
    string color;

public:
    Shape(string color) : color(color) {}
    virtual Shape* clone() = 0;
    virtual void showDetails() = 0;

    virtual ~Shape() = default;
};


// Concrete subclass: Circle
class Circle : public Shape {
private:
    int radius;

public:
    Circle(string color, int radius) : Shape(color), radius(radius){}

    Circle(const Circle& other) : Shape(other.color), radius(other.radius){}

    Shape* clone() override {
        return new Circle(*this);
    }

    void showDetails() override {
        cout << "Circle with color: " << color << " and radius: " << radius << endl;
    }
};


// Concrete subclass: Rectangle
class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(string color, int width, int height) : Shape(color), width(width), height(height){}

    Rectangle(const Rectangle& other) : Shape(other.color), width(other.width), height(other.height){}

    Shape* clone() override {
        return new Rectangle(*this);
    }

    void showDetails() override {
        cout << "Rectangle with color: " << color << ", width: " << width << " and height: " << height << endl;
    }
};

int main()
{
    // Create a circle
    Circle circle("Red", 5);
    circle.showDetails();

    // Clone circle
    Shape* circleClone = circle.clone();
    circleClone->showDetails();

    // Create a rectangle
    Rectangle rect("Blue", 10, 20);
    rect.showDetails();

    // Clone rectangle
    Shape* rectClone = rect.clone();
    rectClone->showDetails();

    // Clean up
    delete circleClone;
    delete rectClone;

    return 0;
}




/*

🔹 Output 🔹
==============================
Circle with color: Red and radius: 5
Circle with color: Red and radius: 5
Rectangle with color: Blue, width: 10 and height: 20
Rectangle with color: Blue, width: 10 and height: 20

🔹 Summary 🔹
==================================================================================
✅ Prototype lets you create new object copies without specifying their exact class.
✅ Helps avoid heavy or complex object instantiations.
✅ Provides a flexible way to produce copies with or without modifications.

*/