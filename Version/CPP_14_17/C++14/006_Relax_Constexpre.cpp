#include <iostream>
using namespace std;

constexpr int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; ++i) res *= i;
    return res;
}

int main() {
    constexpr int val = factorial(5);  // 120
    cout << val << endl;
}
