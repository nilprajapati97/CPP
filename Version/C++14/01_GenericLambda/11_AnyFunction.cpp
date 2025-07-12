
/*
🔹 Example 3: Lambda for Applying Any Function
This example demonstrates how to use a generic lambda to apply any function to a value, showcasing the flexibility of generic lambdas in C++14.

*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    auto apply = [](auto func, auto value) {
        return func(value);  // Generic function application
    };

    // Using int lambda
    cout << apply([](int x) { return x * x; }, 5) << endl;       // Output: 25

    // Using double with std::sqrt
    cout << apply([](double x) { return sqrt(x); }, 16.0) << endl; // Output: 4

    return 0;
}

