
/*
✅ 04. Bridge Pattern
🔸Use Case: Vary both abstraction and implementation independently
Example: Different shapes (Circle, Rectangle) drawn in different APIs (OpenGL, DirectX)

*/

#include <iostream>
using namespace std;

class DrawAPI {
public:
    virtual void drawCircle(int r) = 0;
};

class OpenGL : public DrawAPI {
public:
    void drawCircle(int r) override {
        cout << "Drawing circle using OpenGL with radius " << r << endl;
    }
};

class DirectX : public DrawAPI {
public:
    void drawCircle(int r) override {
        cout << "Drawing circle using DirectX with radius " << r << endl;
    }
};

class Shape {
protected:
    DrawAPI* drawer;
public:
    Shape(DrawAPI* d) : drawer(d) {}
    virtual void draw() = 0;
};

class Circle : public Shape {
    int radius;
public:
    Circle(int r, DrawAPI* d) : Shape(d), radius(r) {}
    void draw() override {
        drawer->drawCircle(radius);
    }
};

int main() {
    Circle c1(10, new OpenGL());
    Circle c2(15, new DirectX());

    c1.draw();
    c2.draw();
}
