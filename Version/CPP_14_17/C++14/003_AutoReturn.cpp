#include <iostream>
using namespace std;

// Function that returns the square of an integer
auto square(int x) {
    return x * x;  // Return type automatically deduced as int
}

int main() {
    int value = 5;
    cout << "Square of " << value << " is " << square(value) << endl;

    return 0;
}
