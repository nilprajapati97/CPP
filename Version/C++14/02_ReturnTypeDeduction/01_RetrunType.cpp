#include <iostream>
#include <typeinfo>
using namespace std;
// C++14: compiler deduces return type from the return statement
// In C++14, this becomes simpler:

auto multiply(int a, int b) {   // mainly focus on return type deduction
    return a * b; // compiler deduces int
}

auto sum(float a, float b) {
    return a + b; // compiler deduces float
}

/*
//This feature in c++ 20 //
//concepts

auto subtract(auto a, auto b) {
    return a - b; // compiler deduces float
}
*/
int main() {
    auto result = multiply(3, 5);
    auto add = sum(3.0f, 5.0f);
    //auto sub = subtract(10, 4.5f);
    
    cout << "Result: " << result << "\n";
    cout << "sum: " << add << "\n";
    //cout << "subtract: " << sub << "\n";

    // Print deduced type name (for verification)
    cout << "Type of result: " << typeid(result).name() << "\n";
    cout << "Type of result: " << typeid(add).name() << "\n";
    //cout << "Type of result: " << typeid(sub).name() << "\n";

    return 0;
}
