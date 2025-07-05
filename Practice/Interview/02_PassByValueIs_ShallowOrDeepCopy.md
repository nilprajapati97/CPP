Is "Pass by Value" a Shallow Copy or Deep Copy in C++?
===============================================================

👉 Pass by value in C++ creates a shallow copy by default, but the actual behavior depends on whether the object contains dynamically allocated memory.

1. Pass by Value - Shallow Copy Behavior
---------------------------------------------------
When an object is passed by value, a copy of the object is created. By default, C++ uses the default copy constructor, which performs a shallow copy.

#include <iostream>

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


🔴 Problem: Dangling Pointer in Shallow Copy
--------------------------------------------------
When func(obj) is called:

->  The default copy constructor creates a shallow copy.
->  Both obj (original) and d (copy) share the same memory address.
->  When d goes out of scope, its destructor deletes the memory.
->  obj.ptr now points to a deleted memory location (dangling pointer).
->  Accessing obj.ptr after the function call can cause undefined behavior! 🚨


2. Making Pass by Value a Deep Copy
============================================================================
To prevent issues, explicitly define a deep copy constructor.

✅ Example: Deep Copy in Pass by Value

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

✅ Solution Using Deep Copy
The deep copy constructor allocates new memory for ptr instead of copying the pointer.
Now, obj and d have separate memory allocations, preventing deletion conflicts


Copy Type	    Behavior in Pass by Value
----------------------------------------------------------------------------------------
Shallow Copy	Default copy constructor is used (pointer is copied, not data).
Deep Copy	    Custom copy constructor must be written (allocates separate memory).


When to Use Deep Copy?
------------------------------
->When your class has dynamically allocated memory (new/delete).To avoid dangling pointers and memory corruption.When copying objects should create independent instances.

