/*

1. get() – Get Raw Pointer
    Returns the raw pointer stored inside the std::unique_ptr without releasing ownership.

*/
#include <iostream>
#include <memory>
using namespace std;

class Car {
public:
    void drive()
     {
        cout << "Driving Car"<<endl;
     }
};

int main() {

    unique_ptr<Car> carPtr = make_unique<Car>();
    
    Car* rawPtr = carPtr.get(); // Get raw pointer without releasing ownership
    rawPtr->drive();            // Still managed by unique_ptr

    return 0;
}
