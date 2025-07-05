#include <iostream>
using namespace std;

class AbstractDevice {
public:
    virtual void start() = 0;

    // Pure virtual destructor
    virtual ~AbstractDevice() = 0;
};

AbstractDevice::~AbstractDevice() {
    cout << "AbstractDevice destroyed\n";
}

class Printer : public AbstractDevice {
public:
    void start() override {
        cout << "Printer started\n";
    }

    ~Printer() {
        cout << "Printer destroyed\n";
    }
};

int main() {
    AbstractDevice* dev = new Printer();
    dev->start();

    delete dev; // Proper destructor chain will be called
    return 0;
}

/*
output:

Printer started
Printer destroyed
AbstractDevice destroyed
// Explanation: The pure virtual destructor allows the class to be abstract while still providing
 a definition for cleanup.
// This ensures that derived classes can implement their own destructors while still allowing
// the base class to perform its cleanup.

// Use case: Useful when you want to enforce a destructor in an abstract class but still need to
// provide a default implementation for cleanup in derived classes.

*/
