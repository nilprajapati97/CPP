
/*
2. release() – Release Ownership
    Releases ownership of the managed object and returns the raw pointer.
    The caller is responsible for manually deleting the object.

*/
#include <iostream>
#include <memory>

using namespace std;

class Car {
public:
    Car()
    {
        cout << "Car Created"<<endl;
    }

    ~Car()
    {
        cout << "Car Destroyed"<<endl;
    }

};

int main() {
    unique_ptr<Car> carPtr = make_unique<Car>();

    Car* rawPtr = carPtr.release(); // Releases ownership
    delete rawPtr;                  // Must manually delete to prevent memory leak

    return 0;
}
