//✅ C++14 Feature: Binary Literals & Digit Separators

/*
🔹 1. Binary Literals: 0b or 0B prefix
===========================================
🔧 Syntax:
---------------

int bin = 0b1101;  // binary literal (equal to decimal 13)


🧠 Why?
-----------------
Improves readability for binary values, especially in bit manipulation, flags, and registers.
// Example:
int flags = 0b101010;  // easier to read than 42 in decimal

Before C++14, you had to use hex or decimal:
int bin = 13;      // less obvious
int bin = 0x0D;    // hex, harder to read in binary context

Now, C++14 allows:
===================
int bin = 0b1101;  // ✅ directly readable
// ✅ Binary literals are more intuitive for bitwise operations and flags


*/

#include <iostream>
using namespace std;

int main() {
    int a = 0b1010; // 10 in binary
    int b = 0b1100; // 12 in binary

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a & b = " << (a & b) << endl;
    return 0;
}
// Output:
// a = 10, b = 12
// a & b = 8