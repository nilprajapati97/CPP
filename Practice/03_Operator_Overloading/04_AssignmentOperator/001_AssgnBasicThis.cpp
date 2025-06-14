#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int val = 0) : value(val) {}  // Constructor

    MyClass& operator=(const MyClass& other) {
        if (this != &other) {  // Self-assignment check
            this->value = other.value;
        }
        return *this;  // Return reference to allow chaining
    }

    void show() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2;

    obj2 = obj1;  // Assignment operator is called

    obj2.show();  // Output: Value: 10

    return 0;
}
