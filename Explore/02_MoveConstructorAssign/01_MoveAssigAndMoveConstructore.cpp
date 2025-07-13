/*
🔹 Definitions:
==================================================================================================================================
✅ Move Constructor:
==================================================================================================================================

        T(T&& other); // Move constructor

Used when a temporary object is used to initialize a new object.
Transfers ownership of resources from other to the new object.
    Automatically called during:
    Return by value
    Passing by value

T obj2 = std::move(obj1);

==================================================================================================================================
✅ Move Assignment Operator:
==================================================================================================================================

        T& operator=(T&& other); // Move assignment

    Used when an existing object is assigned a temporary.
    Releases the current object's resources and steals those from other.
    Automatically called during:
                                obj2 = std::move(obj1);

🔄 Differences
==================================================================================================================================
| Feature                   | Move Constructor                        | Move Assignment Operator                |
| ------------------------- | --------------------------------------- | --------------------------------------- |
| **Purpose**               | Initialize a new object using an rvalue | Assign an existing object from rvalue   |
| **When Called**           | `T obj = std::move(other);`             | `obj = std::move(other);`               |
| **Destroys old content?** | No – object is being constructed        | Yes – object might already hold content |
| **Return type**           | None (constructor)                      | Returns `T&` (`*this`)                  |
| **Defaulted?**            | Yes, if no custom constructor           | Yes, if no custom assignment operator   |
| **Rule of 5/Rule of 3**   | Must be user-defined for resource class | Same – both need explicit definition    |
==================================================================================================================================



*/

#include <iostream>
#include <vector>

using namespace std;
class MyClass {
public:
    vector<int> data;

    MyClass() {
        cout << "Default constructor\n";
    }

    MyClass(const MyClass& other) {
        cout << "Copy constructor\n";
        data = other.data;
    }

    MyClass(MyClass&& other) noexcept {
        cout << "Move constructor\n";
        data = move(other.data);
    }

    MyClass& operator=(MyClass&& other) noexcept {
        cout << "Move assignment\n";
        if (this != &other) {
            data = move(other.data);
        }
        return *this;
    }

    ~MyClass() {
        cout << "Destructor\n";
    }
};

int main() {
    MyClass a;
    MyClass b = move(a); // Move Constructor

    MyClass c;
    c = move(b);         // Move Assignment
}

/*
🧾 Output:
==================================================================================================================================
Default constructor
Move constructor
Move assignment
Destructor
Destructor
Destructor

*/
