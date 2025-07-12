#include <iostream>
using namespace std;

// ✅ constexpr with auto parameter is allowed in C++20
constexpr auto square(auto x) {
    return x * x;
}

int main() {
    // ✅ Case 1: Compile-time evaluation
    constexpr int const_result1 = square(5);
    cout << "Compile-time square: " << const_result1 << endl;

    constexpr float const_result2 = square(2.5f);
    cout << "Compile-time float square: " << const_result2 << endl;

    // ✅ Case 2: Run-time evaluation
    int a;
    cin >> a; // input
    int run_time_result = square(a); // evaluated at run-time
    cout << "Run-time square: " << run_time_result << endl;

    return 0;
}
// C++ 20 allows constexpr functions with auto parameters,
// enabling compile-time evaluation for various types.  
