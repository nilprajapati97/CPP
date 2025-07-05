#include <iostream>
#include <type_traits>   // for std::is_floating_point
#include <concepts>      // for defining concepts
using namespace std;
// ✅ Define a custom concept
template<typename T>
concept FloatingPoint = is_floating_point_v<T>;

// ✅ Lambda constrained by the concept
auto cube = [](FloatingPoint auto x) {
    return x * x * x;
};

int main() {
    double d = 2.5;
    float f = 3.0f;

    std::cout << "Cube of " << d << " = " << cube(d) << '\n';
    std::cout << "Cube of " << f << " = " << cube(f) << '\n';

    // int i = 4;
    // std::cout << cube(i);  // ❌ Compile-time error: int is not floating point

    return 0;
}
// Compile with: g++ -std=c++20 your_file.cpp -o output_binary
// Output:
// Cube of 2.5 = 15.625
// Cube of 3 = 27
