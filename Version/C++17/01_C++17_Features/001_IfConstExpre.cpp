
/*
✅ 2. if constexpr
===============================
🔹 Purpose:
Compile-time branching — only the valid branch is compiled.
*/
#include <iostream>
using namespace std;

template<typename T>
void print(T x) {
    if constexpr (is_integral<T>::value)
        cout << "Integer: " << x << endl;
    else
        cout << "Non-integer: " << x << endl;
}

int main() {
    print(5);       // Integer
    print(3.14);    // Non-integer
    return 0;
}

/*
Output:
===========
Integer: 5
Non-integer: 3.14
Explanation: if constexpr checks type at compile time, so only the relevant branch is compiled.
*/