//✅ From C++20: Constrained Generic Lambdas (Concepts)
/*
✅ Concept Used: std::integral
==================================
std::integral is a concept introduced in C++20 that matches all integral types 
like int, short, long, unsigned int, etc.

This helps restrict templates or lambdas to only accept values that are 
integers — not floating-point or other types.

*/
#include<iostream>
#include <iostream>
#include <concepts>  // Required for std::integral
using namespace std;

int main() {
    // Constrained generic lambda using std::integral
    auto square = [](integral auto x) {
        return x * x;
    };

    cout << "square(5): " << square(5) << "\n";      // OK
    cout << "square(12u): " << square(12u) << "\n";  // OK: unsigned int

    // std::cout << square(3.14); // ❌ Compile-time error: 3.14 is not integral

    return 0;
}
/*
g++ -std=c++20 your_file.cpp -o output_binary


✅ Output:
square(5): 25
square(12u): 144
*/
