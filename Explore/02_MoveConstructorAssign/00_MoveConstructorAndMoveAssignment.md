The **move constructor** and **move assignment operator** are both part of **move semantics** in C++11 and beyond. They enable **efficient transfer of resources** (like heap memory, file handles, etc.) from **temporary objects or r-values**.

---

## 🧠 In-depth Difference Between Move Constructor vs Move Assignment Operator
===================================================================================================

| Aspect              | Move Constructor                      | Move Assignment Operator                |
|---------------------|----------------------------------------|------------------------------------------|
| **Purpose**         | Creates new object by taking           | Transfers resources to an existing       |
|                     | resources from an rvalue.              | object from an rvalue.                   |
| **When Called**     | When constructed from an rvalue.       | When assigned from an rvalue.            |
| **Signature**       | `ClassName(ClassName&&) noexcept`      | `ClassName& operator=(ClassName&&) noexcept` |
| **Lifecycle**       | Happens during object creation.        | Happens after object is already created. |
| **Implicit?**       | Yes, if no copy/move defined.          | Yes, if no copy/move defined.            |
| **Used by STL?**    | Yes (e.g., vector resize, return).     | Yes (e.g., rvalue assignment).           |
| **Self-assignment** | Not needed (new object).               | Must check `if (this != &other)`         |


### ✅ Example Code Demonstrating Both
===================================================================================================
```cpp
#include <iostream>
#include <utility>
using namespace std;

class MyClass {
    int* data;

public:
    // Constructor
    MyClass(int val) {
        data = new int(val);
        cout << "Constructor: " << *data << endl;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept {
        cout << "Move Constructor\n";
        data = other.data;
        other.data = nullptr;
    }

    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        cout << "Move Assignment Operator\n";
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~MyClass() {
        if (data) {
            cout << "Destructor: " << *data << endl;
        } else {
            cout << "Destructor: nullptr" << endl;
        }
        delete data;
    }
};
```

---

### ✅ Test in `main()`
===================================================================================================

```cpp
int main() {
    MyClass a(10);
    MyClass b = std::move(a);   // 🔸 Move Constructor

    MyClass c(20);
    c = std::move(b);           // 🔹 Move Assignment Operator

    return 0;
}
```

---

### 🧾 Output (Explained)
===================================================================================================
```plaintext
Constructor: 10
Move Constructor
Constructor: 20
Move Assignment Operator
Destructor: nullptr     // c = std::move(b); c took over b's data
Destructor: nullptr     // b no longer owns the data
Destructor: nullptr     // a was moved-from
```

---

## 🔍 When to Use Which?
===================================================================================================
* **Move Constructor**: Used when returning objects by value, passing temporaries.
* **Move Assignment**: Used when an existing object is reassigned a temporary.

---

### 📌 Real Example: STL Vector
===================================================================================================
```cpp
std::vector<MyClass> vec;
vec.push_back(MyClass(100)); // uses move constructor if available
vec[0] = MyClass(200);       // uses move assignment operator
```

---

## 🛠️ Summary
========================================================================================================================
| Feature                     | Move Constructor              | Move Assignment                          |
| --------------------------- | ------------------------------|------------------------------------------|
| Constructs new object       | ✅                            | ❌                                       |
| Replaces contents           | ❌                            | ✅                                       |
| Used in:                    | Return by value, temporaries  | Assignment with rvalues                  |
| `noexcept` recommended?     | ✅ Yes                        | ✅ Yes                                   |
| Deletes existing resources? | ❌ (object is new)            | ✅ (old resources must be released first)|

---



🔷 Visual Diagram: Move Constructor vs Move Assignment
========================================================================================================================
┌──────────────────────────────────────┐
│            Move Constructor          │
└──────────────────────────────────────┘
      Used when NEW object is created
           from a temporary (rvalue)

    MyClass temp = MyClass(5);
                 ▲         ▲
                 │         │
         R-value │         │ Constructor
                 └────────> Used to build temp
                 ↓
     MyClass another = std::move(temp);
                     ▲
                     │
            Move Constructor is called
             (another takes temp's data)



┌──────────────────────────────────────┐
│         Move Assignment Operator     │
└──────────────────────────────────────┘
    Used when EXISTING object is assigned
             a temporary (rvalue)

    MyClass a(10);        ← already exists
    a = MyClass(20);      ← rvalue assigned to existing object
        ▲
        │
   Constructor creates temp rvalue
        │
        └──> Move Assignment moves data into `a`
