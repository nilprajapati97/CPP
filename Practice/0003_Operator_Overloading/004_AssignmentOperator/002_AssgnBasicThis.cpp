#include <iostream>
#include <cstring>

class MyClass {
private:
    char* data;

public:
    // Constructor
    MyClass(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Overloaded Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) {  // Self-assignment check
            return *this;
        }

        // Free the existing resource
        delete[] data;

        // Allocate new memory and copy data
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);

        return *this;
    }

    // Destructor
    ~MyClass() {
        delete[] data;
    }

    // Display function
    void show() const {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    MyClass obj1("Hello");
    MyClass obj2;
    
    obj2 = obj1;  // Assignment operator is called
    obj2.show();
    
    return 0;
}
