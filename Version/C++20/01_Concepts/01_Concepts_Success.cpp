#include <iostream>
#include <string>
#include <concepts>

template<typename T>
requires requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;  // constrain: must support a + b
}
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(5, 3) << "\n";                              // OK
    std::cout << add(std::string("Hi "), std::string("there")) << "\n";  // OK

    // ❌ Clear compile error at call site
    std::cout << add(std::string("Hi "), 42) << "\n";  // Error: doesn't satisfy concept
}
