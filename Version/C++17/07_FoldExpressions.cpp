/*
✅ 7. Fold Expressions
========================================
🔹 Purpose:
Simplify variadic template operations — apply an operation to all arguments.

*/
#include <iostream>
using namespace std;

// Fold expression to sum all arguments
// This uses C++17's fold expressions to sum all arguments passed to the function.
// The expression (... + args) expands to (arg1 + arg2 + ... + argN),
// effectively summing all the arguments together.
template<typename... Args>
auto sum(Args... args) {
    return (... + args); // fold expression
}

int main() {
    cout << "Sum: " << sum(1.5, 2.5, 3.7, 4.5) << endl; // Example usage
    cout << "Sum: " << sum(1, 2, 3, 4) << endl;
    return 0;
}

// Output:
// Sum: 12.2
// Sum: 10
//✅ Before: Needed recursion. Now: One-liner.
