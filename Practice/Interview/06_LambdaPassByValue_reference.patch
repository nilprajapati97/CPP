Lambda Functions in C++: Pass by Value, Reference & Parameters
======================================================================

A lambda function in C++ can capture variables by value ([=]) or reference ([&]) and accept parameters

Example: Passing by Value, Reference & Parameters in a Lambda

#include <iostream>

int main() {
    int a = 10, b = 20;

    // 🔹 Capture by VALUE (copies a & b)
    auto addByValue = [=]() {
        return a + b; // Captures a, b by value
    };

    // 🔹 Capture by REFERENCE (modifies original variables)
    auto addByReference = [&]() {
        a += 5; // Changes original 'a'
        return a + b;
    };

    // 🔹 Lambda with Parameters
    auto addWithParams = [](int x, int y) {
        return x + y;
    };

    std::cout << "Add by Value: " << addByValue() << std::endl;  // 30
    std::cout << "Add by Reference: " << addByReference() << std::endl;  // 35
    std::cout << "Modified 'a': " << a << std::endl;  // a = 15
    std::cout << "Lambda with Parameters: " << addWithParams(50, 50) << std::endl;  // 100

    return 0;
}

🔹 Output
Add by Value: 30
Add by Reference: 35
Modified 'a': 15
Lambda with Parameters: 100


Capture Type	        Syntax	                Behavior
-----------------------------------------------------------------------------------------------------
Pass by Value	        [=]() { }	            Copies variables, does not modify original values
Pass by Reference	    [&]() { }	            Uses original variables, can modify them
Pass Parameters	        [](int x, int y) { }	Regular function-style parameters


✅ Best Practice:

Use pass by value ([=]) when you don't want to modify variables inside the lambda.
Use pass by reference ([&]) when you need to modify the captured variables.