#include <iostream>

class Demo {
public:
    int* ptr;

    Demo(int val) { ptr = new int(val); }

    // Deep Copy Constructor
    Demo(const Demo& d) {
        ptr = new int(*d.ptr); // Allocate new memory and copy value
    }

    // Destructor
    ~Demo() { delete ptr; }

    void display() { std::cout << "Value: " << *ptr << std::endl; }
};

void func(Demo d) {
    std::cout << "Inside function: ";
    d.display();
}

int main() {
    Demo obj(10);
    func(obj); // Pass by value, now a deep copy
    obj.display(); // No issue since obj.ptr is separate

    return 0;
}
