✅ What Are Generic Lambdas?
=================================================================
/*
Generic lambdas are a feature introduced in C++14 that allows you to define lambda expressions that can accept parameters of any type. This is done using the `auto` keyword in the parameter list, enabling the lambda to be more flexible and reusable across different types without needing to specify them explicitly.
This feature enhances the expressiveness of lambdas, making them more powerful for generic programming tasks.

Example of Generic Lambda Usage
=================================================================
//🧰 Basic Use Case — Generic Lambda Example   
#include <iostream>
using namespace std;
int main() {
    auto genericLambda = [](auto x) { return x + 1; }; // Generic lambda using auto
    cout << genericLambda(5) << endl;   // Output: 6
    cout << genericLambda(3.14) << endl; // Output: 4.14
    return 0;
}
// Output: 6 4.14
// Explanation: The lambda `genericLambda` can accept any type of argument
// (int, double, etc.) and returns the value incremented by 1. This
// demonstrates the flexibility of generic lambdas in C++14, allowing for
// more concise and adaptable code.

auto in the parameter list makes the lambda a function template.

It behaves like a templated function — works for any type that supports the operation inside the body.
// This allows for writing more generic and reusable code without the need for explicit template definitions.
// This is particularly useful for algorithms and operations that need to work with different data types.
// This feature is part of the C++14 standard, enhancing the capabilities of lambda expressions.
// This is a powerful feature of C++14 that simplifies generic programming by allowing you to write
// concise and flexible code that works with different types.
--------------------------------------------------------------------------------------
In C++11:
    auto lambda = [](int x) { return x + 1; }; // fixed type
In C++14:
    auto lambda = [](auto x) { return x + 1; }; // generic type

