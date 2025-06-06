#include <iostream>
#include <cmath>  // For sqrt()

class Point2D {
private:
    double x, y;

public:
    // 🔹 Constructor
    Point2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // 🔹 Getters
    double getX() const { return x; }
    double getY() const { return y; }

    // 🔹 Setters
    void setX(double x_val) { x = x_val; }
    void setY(double y_val) { y = y_val; }

    // 🔹 Distance between two points
    double distanceTo(const Point2D& other) const {
        return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
    }

    // 🔹 Operator Overloading
    Point2D operator+(const Point2D& other) const {  // Add coordinates
        return Point2D(x + other.x, y + other.y);
    }

    Point2D operator-(const Point2D& other) const {  // Subtract coordinates
        return Point2D(x - other.x, y - other.y);
    }

    bool operator==(const Point2D& other) const {  // Compare points
        return (x == other.x && y == other.y);
    }

    // 🔹 Print point using friend function
    friend std::ostream& operator<<(std::ostream& os, const Point2D& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

// 🔹 Main function to test Point2D class
int main() {
    Point2D p1(3, 4);
    Point2D p2(6, 8);

    std::cout << "Point 1: " << p1 << std::endl;
    std::cout << "Point 2: " << p2 << std::endl;

    std::cout << "Distance: " << p1.distanceTo(p2) << std::endl;

    Point2D p3 = p1 + p2;  // Adding points
    std::cout << "p1 + p2 = " << p3 << std::endl;

    Point2D p4 = p2 - p1;  // Subtracting points
    std::cout << "p2 - p1 = " << p4 << std::endl;

    return 0;
}

