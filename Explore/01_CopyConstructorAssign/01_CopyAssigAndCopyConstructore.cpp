#include <iostream>
using namespace std;

class MyClass {
    int* data;

public:
    // Constructor
    MyClass(int value) {
        data = new int(value);
        cout << "Constructor called. Value = " << *data << endl;
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
        cout << "Copy Constructor called. Value = " << *data << endl;
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
            cout << "Copy Assignment Operator called. Value = " << *data << endl;
        }
        return *this;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called. Value = " << *data << endl;
        delete data;
    }
};

int main() {
    MyClass obj1(10);           // Constructor
    MyClass obj2 = obj1;        // 🔸 Copy Constructor
    MyClass obj3(0);            // Constructor
    obj3 = obj1;                // 🔹 Copy Assignment Operator
    return 0;
}
