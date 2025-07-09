/*
✅ 6. Inline Variables
========================================
🔹 Purpose:
Allow constexpr/static variables to be defined in headers safely.
*/

#include <iostream>
using namespace std;

struct A {
    static inline int x = 10;
};

int main() {
    cout << A::x << endl;
}
// Output:
// 10

/*
Explanation: Inline variables can be defined in headers without violating 
    ODR (One Definition Rule).
Explanation: No need for definition outside class for static members.


✅ Used in header-only libraries without violating ODR (One Definition Rule).
*/