/*
✅ Best C++17 Version with Compile-time Factorial Using Fold
============================================================
// 🔹 Purpose:
Calculate factorial at compile-time using fold expressions.
// 🔹 Characteristics:
- Uses C++17's fold expressions for variadic templates.
- Efficient and concise.
- No recursion needed.

*/

// 1-: Using fold expressions to calculate factorial at compile-time
// ===============================================================================================
// This code calculates the factorial of a number at compile-time using C++17's fold expressions
// and variadic templates. It uses `std::index_sequence` to generate a sequence of indices from 0 to N-1,
// and then applies a fold expression to multiply all the indices plus one together, effectively calculating the factorial of N.
// The `factorial` function takes a size_t parameter `n` and returns the factorial of `n`.
// If `n` is 0, it returns 1 (since 0! = 1).
// The `factorial_fold` function is a helper that takes an `std::index_sequence` and uses a fold expression to compute the factorial by multiplying all indices plus one together.
// The `main` function demonstrates the usage of the `factorial` function by calculating the factorial of 5, 0, and 1, and printing the results.
// This approach is efficient and leverages C++17 features to perform the calculation at compile-time
// without the need for recursion or iterative loops.
// This code is a good example of how to use C++17 features like fold expressions and `std::index_sequence` to perform compile-time calculations in a clean and efficient manner.

/* Factorial at Compile-Time */
/*
#include <iostream>
#include <utility> // for std::index_sequence and make_index_sequence

// Expand 0 to N-1 as a parameter pack
template <size_t... Is>
constexpr size_t factorial_fold(std::index_sequence<Is...>) {
    // ❌ ERROR: n is not constexpr here (it's runtime input)
    return ((Is + 1) * ...); // 1 * 2 * ... * N
}

constexpr size_t factorial(size_t n) {
    if (n == 0) return 1;
    return factorial_fold(std::make_index_sequence<static_cast<size_t>(n)>{});
}

int main() {
    std::cout << "Factorial(5): " << factorial(5) << "\n";  // Output: 120
    std::cout << "Factorial(0): " << factorial(0) << "\n";  // Output: 1
    std::cout << "Factorial(1): " << factorial(1) << "\n";  // Output: 1
}
*/
/*
Output:
Factorial(5): 120
Factorial(0): 1
Factorial(1): 1
*/

/*
🔥 Why the Error?
=======================
std::make_index_sequence<n> expects a compile-time constant — but n is a runtime variable.

✅ Fix: Use if constexpr for known values or just loop at runtime
If you're writing a runtime factorial, just use a loop:



*/

#include <iostream>
#include <utility>

template <size_t... Is>
constexpr size_t factorial_fold(std::index_sequence<Is...>) {
    return ((Is + 1) * ...);  // 1 * 2 * ... * N
}

template <size_t N>
constexpr size_t factorial() {
    return factorial_fold(std::make_index_sequence<N>{});
}

int main() {
    constexpr size_t fact5 = factorial<5>();  // ✅ Compile-time
    std::cout << "Factorial(5): " << fact5 << "\n";
    return 0;
}
/*
Output:
===============
Factorial(  5): 120

🧠 Summary
====================================================================================
| Want                       | Use                                                  |
| -------------------------- | ---------------------------------------------------- |
| **Runtime factorial**      | Use loop with `for`                                  |
| **Compile-time factorial** | Use `template<size_t N>` with `index_sequence`       |
| **Fold expressions**       | Only valid when all values are known at compile time |



- Compile-time factorial calculation using C++17 features.
- Efficient and avoids recursion.
- Demonstrates advanced template metaprogramming techniques.
*/

