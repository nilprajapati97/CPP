//VtableBehaviour

#include <iostream>
class Base {
public:
    virtual void show() { std::cout << "Base\n"; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived\n"; }
};

int main() {
    Base* ptr = new Derived();
    ptr->show(); // prints "Derived" due to vtable
    delete ptr;
}
