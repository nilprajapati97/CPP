/*

✅ 4. std::variant — Type-Safe Union
================================================================================================
🔹 What is std::variant?
---------------------------------
std::variant<Ts...> is a type-safe union that can hold exactly one value of the types 
T1, T2, ..., Tn at a time.

It replaces unsafe C-style union with:
- Type safety: Ensures only one type is active at a time.
- Type tracking: Keeps track of which type is currently held.
- Compiler-checked access: Accessing the value requires checking the type.
- Exception safety: Provides strong exception guarantees when accessing the value.


✅ Q1. What is std::variant and how is it different from union?
================================================================================================
| Feature                        | `std::variant`                   | C-style `union`                  |
| ------------------------------ | -------------------------------  | -------------------------------- |
| Type Safety                    | ✅ Knows current type            | ❌ No type info                   |
| Type Checked Access            | ✅ via `std::get<T>()`           | ❌ Programmer must track manually |
| Multiple non-trivial types     | ✅ e.g., `std::string`, `vector` | ❌ Only PODs safely               |
| Holds Constructors/Destructors | ✅ Calls the correct ones        | ❌ Undefined for non-POD types    |
| Runtime Type Index             | ✅ via `.index()`                | ❌ Not available                  |
================================================================================================

✅ Q2. What happens if you access the wrong type from a std::variant?
================================================================================================
If you try to access a type not currently held using std::get<T>(), it throws a 
std::bad_variant_access exception.

std::variant<int, std::string> v = "hello";

try {
    int i = std::get<int>(v);  // ❌ throws std::bad_variant_access
} catch (const std::bad_variant_access& e) {
    std::cout << "Exception: " << e.what() << "\n";
}

✅ To avoid this, use:
----------------------------

std::holds_alternative<T>(v) before accessing

std::visit() — safest and most flexible approach

🧠 Challenge:
-------------------------------------------------------
Write a std::variant<int, float, std::string> and a visitor that prints the type and value using std::visit.




*/

#include <iostream>
#include <variant>
#include <string>

// Visitor with overloaded operator()
struct PrintVisitor {
    void operator()(int i) const {
        std::cout << "int: " << i << "\n";
    }

    void operator()(float f) const {
        std::cout << "float: " << f << "\n";
    }

    void operator()(const std::string& s) const {
        std::cout << "string: " << s << "\n";
    }
};

int main() {
    // Declare variant
    std::variant<int, float, std::string> v;

    // Assign int
    v = 42;
    std::visit(PrintVisitor{}, v);  // Output: int: 42

    // Assign float
    v = 3.14f;
    std::visit(PrintVisitor{}, v);  // Output: float: 3.14

    // Assign string
    v = std::string("hello");
    std::visit(PrintVisitor{}, v);  // Output: string: hello

}
/*
Output
===========================
int: 42
float: 3.14
string: hello


🧠 Modernized with C++17 “overload” Helper (optional):
// Overload helper for C++17

template<class... Ts>
struct Overloaded : Ts... {
    using Ts::operator()...;
};
template<class... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;

std::visit(Overloaded{
    [](int i)      { std::cout << "int: " << i << "\n"; },
    [](float f)    { std::cout << "float: " << f << "\n"; },
    [](const std::string& s) { std::cout << "string: " << s << "\n"; }
}, v);


🧠 Summary
=================================================================================================
| Operation         | Best Practice                              |
| ----------------- | ------------------------------------------ |
| Assigning a value | `v = T{}`                                  |
| Safe access       | `std::visit(visitor, v)`                   |
| Checking type     | `std::holds_alternative<T>(v)`             |
| Access with risk  | `std::get<T>(v)` (throws if type mismatch) |
================================================================================================


*/