#include <iostream>
#include <vector>
using namespace std;

class Demo {
public:
    int* ptr;

    Demo(int val) { ptr = new int(val); }

    // Destructor to free memory
    ~Demo() { delete ptr; }

    void display() { std::cout << "Value: " << *ptr << std::endl; }
};

// Function receiving object by value
void func(Demo d) {
    std::cout << "Inside function: ";
    d.display();
}

int main() {
    Demo obj(10);
    func(obj); // Pass by value (shallow copy occurs)
    obj.display(); // Still accessible, but potential issue if deleted in func()

    return 0;
}
