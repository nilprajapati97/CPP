#include <iostream>
#include <cstdlib> // For malloc and free

using namespace std;

class MyClass {
public:
    int data;

    // Constructor
    MyClass(int val = 0) : data(val) {
        cout << "Constructor called, data = " << data <<endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called, data = " << data << endl;
    }

    // Overloading new operator
    void* operator new(size_t size) {
        cout << "Custom new operator called, size = " << size << endl;
        void* ptr = malloc(size);
        if (!ptr) {
            throw bad_alloc();
        }
        return ptr;
    }

    // Overloading delete operator
    void operator delete(void* ptr) {
        cout << "Custom delete operator called" <<endl;
        free(ptr);
    }
};

int main() {
    // Using overloaded new
    MyClass* obj = new MyClass(42);
    
    // Using overloaded delete
    delete obj;

    return 0;
}
