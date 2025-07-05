#include <iostream>
using namespace std;

class Sample {
public:
    int x;

    // No constructors, destructors, or assignment operators defined!
    // So the compiler will generate them automatically.
};

int main() {
    Sample a;            // ✅ Default Constructor
    a.x = 10;

    Sample b = a;        // ✅ Copy Constructor
    b.x = 20;

    Sample c;            
    c = b;               // ✅ Copy Assignment Operator

    cout << "a.x = " << a.x << endl;
    cout << "b.x = " << b.x << endl;
    cout << "c.x = " << c.x << endl;

    return 0;            // ✅ Destructor called automatically for a, b, c
}
