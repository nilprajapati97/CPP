#include <iostream>
using namespace std;

struct A {
    static inline int x = 10;
};

int main() {
    cout << A::x << endl;
}
//Explanation: No need for definition outside class for static members.