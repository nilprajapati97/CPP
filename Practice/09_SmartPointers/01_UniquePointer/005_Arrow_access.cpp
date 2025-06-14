/*
5. operator* and operator-> – Access Managed Object
    Used to access the object inside std::unique_ptr.

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

    carPtr->drive(); // Access using operator->

    (*carPtr).drive(); // Access using operator*

    return 0;
}

