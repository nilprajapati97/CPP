/*
   3. reset() – Reset or Replace Managed Object
   Deletes the existing object and replaces it with a new one (if provided).
   If called without arguments, it deletes the managed object

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

	carPtr.reset(new Car()); // Replaces existing Car with a new one

	carPtr.reset(); // Deletes the object and resets pointer to nullptr

	return 0;
}
