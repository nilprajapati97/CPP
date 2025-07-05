/*
Certainly! Let's walk through the use of constexpr functions in C++—including your 
square() example—with a full explanation, valid use cases, and how it differs from regular
functions.
*/

#include <iostream>
using namespace std;

// ✅ A constexpr function to compute square at compile-time if possible
constexpr int square(int x) {
    int result = x * x;
    return result;
}

int main() {
    // ✅ Case 1: evaluated at compile time
    constexpr int const_result = square(5); // evaluated at compile time
    cout << "Compile-time square: " << const_result << endl;

    // ✅ Case 2: evaluated at run time
    int a;
    cin >> a; // user input
    int run_time_result = square(a); // evaluated at run time
    cout << "Run-time square: " << run_time_result << endl;

    return 0;
}
/*
📘 What is constexpr?
=================================================================================
constexpr means evaluated at compile-time, if given compile-time constant input.

Introduced in C++11, improved in C++14 (support for loops and local variables inside).

It allows:
    Compile-time computation
    Use in constant expressions
    Use in constexpr contexts like array sizes or template parameters


🧠 Breakdown of square() function
================================================================================
constexpr int square(int x) {
    int result = x * x;
    return result;
}
// ✅ This function computes the square of an integer.
// ✅ If called with a compile-time constant, it will be evaluated at compile time.

| Part        | Meaning                                                  |
| ----------- | -------------------------------------------------------- |
| `constexpr` | The function is eligible for **compile-time evaluation** |
| `int x`     | Accepts an integer as input                              |
| `result`    | Local variable — allowed in C++14 and later              |
| `return`    | Returns the squared value                                |


🔬 Compile-Time vs Run-Time
================================================================================

✅ Compile-time example:
------------------------------
constexpr int val = square(4);  // Computed at compile time
int arr[val];                   // OK: array size must be constant


❌ Run-time example:
-----------------------------
int x;
std::cin >> x;
int y = square(x); // evaluated at runtime, cannot be used for constexpr array size
// ✅ This is perfectly valid, but not constexpr since x is not a compile-time constant.


✅ When Can You Use constexpr?
================================================================================
| Context                  | Can use `constexpr`?  |
| ------------------------ | --------------------  |
| Constant global variable | ✅ Yes                |
| Switch-case label        | ✅ Yes                |
| Array size               | ✅ Yes                |
| Template argument        | ✅ Yes                |
| Runtime input            | ❌ No                 |


⚠️ Requirements for a valid constexpr function:
================================================================================
1. Must return a literal type (like int, float, pointer, etc.)
2. Should avoid things like:
//    - Dynamic memory allocation (new/delete)
//    - File I/O
//    - Mutexes

3.From C++14, can include:
    Loops
    Local variables
    Multiple return paths

🧮 Bonus: Use in Template
================================================================================
You can use constexpr functions in templates to compute values at compile time:
template<int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <int N>
struct Square {
    static constexpr int value = square(N);  // evaluated at compile time
};

std::cout << Square<6>::value << "\n"; // prints 36

🧠 Summary
==================================================================================
| Feature          | Details                                                      |
| ---------------- | -------------------------------------------------------------|
| ✅ Compile-time   | Safer, faster, and more optimized                           |
| 🧼 Clean syntax   | Avoids macros or hard-coded constants                       |
| ⚡ Faster runtime  | Result is computed during compilation                       |
| 🔥 Use case       | Embedded systems, templates, constexpr arrays, optimization |


*/