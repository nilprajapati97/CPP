#include <iostream>
using namespace std;

template<typename T>
void print(T x) {
    if constexpr (is_integral<T>::value)
        cout << "Integer: " << x << endl;
    else
        cout << "Non-integer: " << x << endl;
}

int main() {
    print(5);       // Integer
    print(3.14);    // Non-integer
}
