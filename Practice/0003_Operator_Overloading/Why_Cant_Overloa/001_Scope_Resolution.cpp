#include <iostream>

/*
1. :: (Scope Resolution Operator)
================================
    -> Why it can't be overloaded:
    -> The scope resolution operator (::) is used to specify a namespace or class scope.
        The compiler must determine the scope of an identifier at compile-time, so allowing overloading would break this behavior.
 *
 *
 *
 *
 * */
class A {
public:
    static int x;
};

int A::x = 10;

int main() {
    std::cout << A::x << std::endl;  // Resolves to class A's x
    return 0;
}

/*
If we could overload ::, it would introduce ambiguity in name resolution, making compilation impossible.
*/