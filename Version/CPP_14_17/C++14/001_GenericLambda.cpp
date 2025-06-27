#include <iostream>
using namespace std;

int main() {
    auto add = [](auto a, auto b) { return a + b; };
    cout << add(5, 3.2) << endl;  // Output: 8.2
}
/*

Explanation: auto in lambda allows any type — int, float, etc. No need for template or function overloading.

*/