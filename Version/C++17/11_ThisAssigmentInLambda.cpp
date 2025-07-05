#include <iostream>
using namespace std;
class A {
    int x = 5;
public:
    void show() {
        auto l = [=, this]() { cout << x << endl; };
        l();
    }
};
int main() {
    A obj;
    obj.show();
}

/*
Output:
5
Explanation: Captures `this` and all variables by value, allowing access to class members in
the lambda. This is useful when you need to access class members inside a lambda without
modifying them. It ensures the lambda can access the class's state even if the lambda is
executed after the class instance goes out of scope.
This is particularly useful in asynchronous programming or when passing lambdas to
functions that may execute later, ensuring the lambda has access to the class's state.
// 🔥 Why use this? 
// ========================================================
// It allows you to capture the class instance (`this`) and all variables by value,
// ensuring the lambda can access the class's state even if the lambda is executed later.
// This is particularly useful in asynchronous programming or when passing lambdas to
// functions that may execute later, ensuring the lambda has access to the class's state.

*/
