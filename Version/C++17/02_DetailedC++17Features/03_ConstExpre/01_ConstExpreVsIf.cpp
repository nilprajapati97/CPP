/*

Q1. What is the difference between if constexpr and if?
=================================================================================================

| Feature                     | `if`                      | `if constexpr` (C++17+)              |
| --------------------------- | --------------------------| -------------------------------------|
| Runtime evaluated           | ✅ Yes                    | ❌ No (compile-time only)            |
| Compile-time branch removal | ❌ No                     | ✅ Yes, dead branches are discarded  |
| Used in templates           | ✅ (but may cause errors) | ✅ (no errors in discarded branch)   |

template<typename T>
void func(T value) {
    if constexpr (std::is_integral_v<T>)
        std::cout << "Integral: " << value << "\n";
    else
        std::cout << "Not integral\n";
}

✅ Q2. How does if constexpr affect template instantiation?
===============================================================================================
It removes the unchosen branch at compile time.

Prevents invalid code from being compiled, even if it exists in the unselected path.

This is not possible with a regular if, which instantiates both paths before runtime.

🧠 Challenge: Function that Adds or Concatenates using if constexpr
---------------------------------------------------------------------------
🔸 Requirements:
                    Use templates
                    If arguments are integers → add
                    If they are strings → concatenate
                    Use if constexpr to handle both



*/

#include <iostream>
#include <type_traits>
#include <string>

template<typename T>
T combine(T a, T b) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Adding integers: ";
        return a + b;
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::cout << "Concatenating strings: ";
        return a + b;
    } else {
        static_assert(std::is_integral_v<T> || std::is_same_v<T, std::string>,
                      "combine() only supports int or std::string");
    }
}

//✅ Usage Example:

int main() {
    int sum = combine(10, 20);
    std::cout << sum << "\n";  // Output: 30

    std::string result = combine(std::string("Hello "), std::string("World"));
    std::cout << result << "\n";  // Output: Hello World

    int sumfloat = combine(10.4, 20.6);
    std::cout << sumfloat << "\n";  // Output: 30

    return 0;
}
/*
Output
============
Adding integers: 30
Concatenating strings: Hello World


Faulty case
===============================================

int sumfloat = combine(10.4, 20.6);
std::cout << sumfloat << "\n";  // X

Assert
======================================
01_ConstExpreVsIf.cpp: In instantiation of ‘T combine(T, T) [with T = double]’:
01_ConstExpreVsIf.cpp:68:27:   required from here
01_ConstExpreVsIf.cpp:53:45: error: static assertion failed: combine() only supports int or std::string
   53 |         static_assert(std::is_integral_v<T> || std::is_same_v<T, std::string>,
      |                       ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
01_ConstExpreVsIf.cpp:53:45: note: ‘(((bool)std::is_integral_v<double>) || ((bool)std::is_same_v<double, std::__cxx11::basic_string<char> >))’ evaluates to false


*/

