#include <iostream>

using namespace std;

class Functor {
public:
    // Overloading function call operator
    void operator()(const string& msg) {
        cout << "Functor called with message: " << msg << endl;
    }
};

int main() {
    Functor functorObj; // Creating an object of Functor class
    functorObj("Hello, C++!"); // Using the object like a function

    return 0;
}
