✅ What Changed in C++14?
================================================================
Before C++14, if you used auto in a function declaration, the compiler needed explicit help via a trailing return type (C++11):

// C++11: must use '->' for trailing return type
auto multiply(int a, int b) -> int {
    return a * b;
}
In C++14, this becomes simpler:
=================================================================
// C++14: compiler deduces return type from the return statement
auto multiply(int a, int b) {
    return a * b;
}
The compiler automatically infers the return type based on a * b.