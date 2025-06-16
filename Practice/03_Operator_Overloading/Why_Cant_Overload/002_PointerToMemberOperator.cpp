#include <iostream>

/*
2. .* (Pointer-to-Member Operator)
================================
Why it can't be overloaded:
    -> The pointer-to-member operator (.*) is used to access members through a pointer to a member of a 
       class.
    -> It is a low-level operator that directly interacts with the memory layout of an object.
 *
 *
 * */
#include <iostream>
using namespace std;

class A {
public:
    int val;
    A(int v) : val(v) {}
};

int main() {
    A obj(10);
    int A::*ptr = &A::val;  // Pointer to member variable
    cout << obj.*ptr << endl;  // Accessing value using .* operator
    return 0;
}


/*
    If .* were overloadable, it could break how C++ resolves memory access through pointers.
*/