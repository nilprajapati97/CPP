// C++14 and C++17 Features in One File
#include <iostream>
#include <tuple>
#include <memory>
#include <optional>
#include <variant>
#include <any>
#include <filesystem>
#include <type_traits>
#include <string>
using namespace std;
namespace fs = std::filesystem;

// C++14 Generic Lambda
void genericLambda() {
    auto add = [](auto a, auto b) { return a + b; };
    cout << "Generic Lambda: " << add(2, 3.5) << endl;
}

// C++14 decltype(auto)
decltype(auto) getVal() {
    int x = 42;
    return x;
}

// C++14 Function Return Deduction
auto square(int x) {
    return x * x;
}

// C++14 Binary Literal and Digit Separator
void binaryLiteral() {
    int b = 0b1010;
    int large = 1'000'000;
    cout << "Binary: " << b << ", Separated: " << large << endl;
}

// C++14 make_unique
void smartPointer() {
    auto ptr = make_unique<int>(99);
    cout << "Smart Pointer: " << *ptr << endl;
}

// C++14 Relaxed constexpr
constexpr int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

// C++14 Lambda Capture by Move
void lambdaMove() {
    auto uptr = make_unique<int>(50);
    auto l = [p = move(uptr)] { cout << "Moved ptr: " << *p << endl; };
    l();
}

// C++17 if constexpr
template<typename T>
void typeCheck(T val) {
    if constexpr (is_integral<T>::value)
        cout << "Integral: " << val << endl;
    else
        cout << "Non-Integral: " << val << endl;
}

// C++17 Structured Bindings
void structuredBindings() {
    tuple<int, string> t = {1, "Anil"};
    auto [id, name] = t;
    cout << "Structured: " << id << ", " << name << endl;
}

// C++17 std::optional
void optionalExample() {
    optional<int> val = 42;
    if (val) cout << "Optional: " << *val << endl;
}

// C++17 std::variant
void variantExample() {
    variant<int, string> data;
    data = "Hello"s;
    cout << "Variant: " << get<string>(data) << endl;
}

// C++17 std::any
void anyExample() {
    any a = string("Test");
    cout << "Any: " << any_cast<string>(a) << endl;
}

// C++17 Inline Variables
struct MyStatic {
    static inline int val = 99;
};

// C++17 Filesystem
void listFiles() {
    cout << "Files in current directory:\n";
    for (const auto& entry : fs::directory_iterator("."))
        cout << " - " << entry.path() << endl;
}

// C++17 Nested Namespaces
namespace company::product::module {
    void show() {
        cout << "Nested Namespace Accessed" << endl;
    }
}

// C++17 Lambda [=, this]
class Demo {
    int x = 10;
public:
    void display() {
        auto l = [=, this] { cout << "Lambda this: " << x << endl; };
        l();
    }
};

int main() {
    genericLambda();
    cout << "decltype(auto): " << getVal() << endl;
    cout << "Function Deduction: " << square(5) << endl;
    binaryLiteral();
    smartPointer();
    cout << "Constexpr factorial: " << factorial(5) << endl;
    lambdaMove();
    typeCheck(42);
    typeCheck(3.14);
    structuredBindings();
    optionalExample();
    variantExample();
    anyExample();
    cout << "Inline variable: " << MyStatic::val << endl;
    listFiles();
    company::product::module::show();
    Demo d;
    d.display();
    return 0;
}
