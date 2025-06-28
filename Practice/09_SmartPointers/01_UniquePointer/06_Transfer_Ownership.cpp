
/*
6. std::move() – Transfer Ownership
    Since std::unique_ptr cannot be copied, use std::move to transfer ownership.
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

void takeOwnership(unique_ptr<Car> car)
{
    cout << "Ownership Transferred\n";
}

int main() {
    unique_ptr<Car> carPtr = make_unique<Car>();

    takeOwnership(move(carPtr)); // Ownership transferred

    return 0;
}
