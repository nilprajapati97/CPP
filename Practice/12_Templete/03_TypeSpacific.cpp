#include <iostream>
using namespace std;

// Generic template
template <typename T>
class Printer {
public:
    void print(T data) {
        cout << "Generic: " << data << endl;
    }
};

// Template specialization for char*
template <>
class Printer<char*> {
public:
    void print(char* data) {
        cout << "String: " << data << endl;
    }
};

// Template specialization for const char*
template <>
class Printer<const char*> {
public:
    void print(const char* data) {
        cout << "Const String: " << data << endl;
    }
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(42); // Output: Generic: 42

    Printer<double> doublePrinter;
    doublePrinter.print(3.14); // Output: Generic: 3.14

    char str[] = "Hello";
    Printer<char*> charPtrPrinter;
    charPtrPrinter.print(str); // Output: String: Hello

    const char* cstr = "World";
    Printer<const char*> constCharPtrPrinter;
    constCharPtrPrinter.print(cstr); // Output: Const String: World

    return 0;
}
