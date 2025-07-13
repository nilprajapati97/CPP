#include <iostream>

class Adder {
public:
    // Overloaded function call operator
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    Adder add;
    int result = add(5, 10); // Calls operator()
    std::cout << "Sum: " << result << std::endl;

    return 0;
}
