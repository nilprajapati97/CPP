🧩 What Is Object Copying in C++?
==========================================================================================================================
C++ allows copying objects using:

* **Copy Constructor** → used during object creation.
* **Copy Assignment Operator** → used during object assignment after creation.

They both **copy data from one object to another**, but the **timing and semantics differ**.

---

## 🔁 Copy Constructor
==========================================================================================================================
### 📌 Definition

```cpp
ClassName(const ClassName& other);
```

### 📍 When Is It Called?
==========================================================================================================================
* When you create a **new object** from an existing object.
* Example situations:

  * `ClassName obj2 = obj1;`
  * Passing by value: `void func(ClassName obj);`
  * Returning by value: `return obj;`

### 📦 Example
==========================================================================================================================
```cpp
class Sample {
    int x;
public:
    Sample(int val) : x(val) {}

    // Copy Constructor
    Sample(const Sample& other) {
        x = other.x;
        std::cout << "Copy Constructor called\n";
    }
};
```

```cpp
Sample a(5);
Sample b = a;  // 🔹 Copy Constructor called
```

---

## 📝 Copy Assignment Operator
==========================================================================================================================
### 📌 Definition

```cpp
ClassName& operator=(const ClassName& other);
```

### 📍 When Is It Called?
==========================================================================================================================
* When you assign to an **already existing object**.
* Example:

  ```cpp
  ClassName obj1(10);
  ClassName obj2(20);
  obj2 = obj1;  // 🔸 Copy Assignment Operator
  ```

### 📦 Example
==========================================================================================================================
```cpp
class Sample {
    int x;
public:
    Sample(int val) : x(val) {}

    // Copy Assignment Operator
    Sample& operator=(const Sample& other) {
        if (this != &other) {
            x = other.x;
            std::cout << "Copy Assignment called\n";
        }
        return *this;
    }
};
```

---

## 🔍 Key Differences Table
==========================================================================================================================
| Aspect                | Copy Constructor                          | Copy Assignment Operator                   |
| --------------------- | ----------------------------------------- | ------------------------------------------ |
| **Purpose**           | Creates a new object from an existing one | Assigns data to an existing object         |
| **Called When**       | New object is initialized                 | Assignment after object is already created |
| **Syntax**            | `ClassName(const ClassName&)`             | `ClassName& operator=(const ClassName&)`   |
| **Involves**          | Memory allocation (new object)            | Possible cleanup + overwrite               |
| **Self-assignment?**  | Not applicable                            | Must check `if (this != &other)`           |
| **Default Provided?** | Yes (shallow copy unless user-defined)    | Yes (shallow copy unless user-defined)     |

---

## 💡 Deep Concept: Shallow vs Deep Copy
==========================================================================================================================
* **Shallow Copy**: Copies pointer addresses; both objects point to same memory → dangerous for resource-owning classes.
* **Deep Copy**: Allocates new memory and copies data → safe and expected for user-defined types.

---

## 🧪 Full Working Code Example
==========================================================================================================================
```cpp
#include <iostream>
using namespace std;

class MyClass {
    int* data;

public:
    MyClass(int val) {
        data = new int(val);
        cout << "Constructor\n";
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);  // Deep copy
        cout << "Copy Constructor\n";
    }

    // Copy Assignment
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
            cout << "Copy Assignment Operator\n";
        }
        return *this;
    }

    ~MyClass() {
        cout << "Destructor: " << *data << endl;
        delete data;
    }
};

int main() {
    MyClass a(10);
    MyClass b = a;    // 🔹 Copy Constructor
    MyClass c(5);
    c = a;            // 🔸 Copy Assignment
}
```

---

## 🧠 Interview Tip
==========================================================================================================================
Explain with:

* When it's called
* Why deep copy matters
* How STL classes behave similarly (like `std::vector`)

---

Let me know if you'd like to include **move constructor vs move assignment** in the same style!
