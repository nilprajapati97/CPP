/*
✅ Full C++ Code: 5 Default Functions (Explicitly Defined + Called)
If you write no special member functions, C++ automatically provides:

    ✅ Default Constructor

    ✅ Copy Constructor

    ✅ Copy Assignment Operator

    ✅ Destructor

    ✅ Address-of operator (legacy, rarely used now)

*/

#include <iostream>
using namespace std;

class Sample {
public:
    int x;

    // 1️⃣ Default Constructor
    Sample() {
        cout << "Default Constructor called\n";
        x = 15;
    }

    // 2️⃣ Copy Constructor
    Sample(const Sample& other) {
        cout << "Copy Constructor called\n";
        x = other.x;
    }

    // 3️⃣ Copy Assignment Operator
    Sample& operator=(const Sample& other) {
        cout << "Copy Assignment Operator called\n";
        if (this != &other) {
            x = other.x;
        }
        return *this;
    }

    // 4️⃣ Destructor
    ~Sample() {
        cout << "Destructor called for x = " << x << endl;
    }

    // 5️⃣ Address-of Operator (optional / legacy)
    Sample* operator&() {
        cout << "Custom address-of (&) operator called\n";
        return this;
    }
};

int main() {
    // ✅ 1. Default Constructor
    Sample obj1;

    // ✅ 2. Copy Constructor
    Sample obj2 = obj1;

    // ✅ 3. Copy Assignment Operator
    Sample obj3;
    obj3 = obj1;

    // ✅ 4. Address-of Operator (Custom)
    Sample* ptr = &obj1;

    // ✅ 5. Destructor called automatically at end of scope
    return 0;
}
/*
✅ Output:
====================================
Default Constructor called
Copy Constructor called
Default Constructor called
Copy Assignment Operator called
Custom address-of (&) operator called
Destructor called for x = 0
Destructor called for x = 0
Destructor called for x = 0

*/