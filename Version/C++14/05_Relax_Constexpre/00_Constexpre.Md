
✅ What is constexpr in C++?
======================================================================================================
constexpr (short for constant expression) tells the compiler:

"This value or function can (and should) be evaluated at compile time, if possible."

Introduced in C++11, and enhanced in C++14, C++17, and especially C++20.

🧠 Purpose of constexpr
========================================================================================================
Improve performance by computing values at compile time

Enable compile-time logic, metaprogramming, and static checks

Used in embedded systems, templates, constexpr containers, etc.


| Use Case           | Example                       | Since  |
| ------------------ | ----------------------------- | ------ |
| Constant variables | `constexpr int x = 10;`       | C++11  |
| Functions          | `constexpr int square(int x)` | C++11  |
| If conditions      | `if constexpr`                | C++17  |
| Constructors       | `constexpr MyClass(...)`      | C++11+ |
| Lambdas            | `constexpr auto lambda = ...` | C++17+ |
| Virtual functions  | `constexpr virtual`           | C++20  |
