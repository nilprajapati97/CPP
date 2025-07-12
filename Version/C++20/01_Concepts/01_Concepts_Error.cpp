#include <iostream>
#include <string>

template<typename T>
T add(T a, T b) {
    return a + b; // This will fail if `+` is not supported for T
}

int main() {
    std::cout << add(5, 3) << "\n";            // ✅ Works: int + int
    std::cout << add(std::string("Hi "), std::string("there")) << "\n"; // ✅ Works: string + string

    // ❌ Compile-time error: string + int is invalid
    std::cout << add(std::string("Hi "), 42) << "\n";  
}

/*
Output:
8
Hi there
error: no matching function for call to 'add(std::__cxx11::basic_string<char>, int)'
// note: candidate template ignored: substitution failure [with T = std::__cxx11::basic_string<char>]:
    no match for 'operator+' (operand types are 'std::__cxx11::basic_string<char>' and 'int')

// Note: This code demonstrates a template function that works with types supporting the '+' operator.
// It will fail at compile time if the '+' operator is not defined for the given type.
// This is a demonstration of template specialization and compile-time type checking in C++.
// This code is a simple example of how C++ templates can be used to create generic functions


*/