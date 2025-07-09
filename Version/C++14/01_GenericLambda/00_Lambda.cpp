#include <iostream>
using namespace std;

int main() {
    auto add = [](auto a, auto b) { return a + b; };
    cout << "Sum: " << add(5, 3) << endl;          // Output: 8
    cout << "Sum: " << add(5.5, 2.7) << endl;      // Output: 8.2
    cout << "Sum: " << add(3.14f, 2.86f) << endl;  // Output: 6
    cout << "Sum: " << add(1, 2) << endl;          // Output: 3
    //cout << add("Anil", "Prarajapati") << endl;  // X
    cout << "Sum: " << add(string("Anil "), string("Prarajapati")) << endl;  // Output: Anil Prarajapati
}
/*
output:
===========
Sum: 8
Sum: 8.2
Sum: 6
Sum: 3
Sum: Anil Prarajapati

Explanation: auto in lambda allows any type — int, float, etc. No need for template or function overloading.

*/

