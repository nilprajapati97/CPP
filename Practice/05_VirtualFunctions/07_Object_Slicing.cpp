#include <iostream>
using namespace std;

class Base {
public:
    int baseData = 1;

    virtual void print() {
        cout << "Base print()\n";
    }
};

class Derived : public Base {
public:
    int derivedData = 2;

    void print() override {
        cout << "Derived print()\n";
    }
};

int main() {
    Derived d;
    Base b = d;  // ❗ Object slicing happens here
    b.print();   // 🔸 prints: Base print()

    cout << "Base data: " << b.baseData << endl;
    // cout << b.derivedData;  // ❌ Error: derivedData doesn't exist in b
}
