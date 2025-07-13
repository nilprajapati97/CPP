#include <iostream>
using namespace std;

// ✅ Factorial as a template (compile-time recursion)
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

// ✅ Base case
template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

// ✅ Square as a template (compile-time calculation)
template <int N>
struct Square {
    static constexpr int value = N * N;
};

int main() {
    constexpr int fact5 = Factorial<5>::value;   // 5! = 120
    constexpr int square7 = Square<7>::value;    // 7² = 49

    cout << "Factorial<5> = " << fact5 << endl;
    cout << "Square<7> = " << square7 << endl;

    return 0;
}
