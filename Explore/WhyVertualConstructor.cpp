#include<iostream>
using namespace std;
struct Base {

	public:
		Base() {

			cout<<"In base class constructor"<<endl;
		}
		virtual ~Base()
		//~Base()
		{

			cout<<"In base class destructore"<<endl;
		}
};

struct Derived : Base {
	int* data;
	Derived() : data(new int[100]) {
		cout<<"In derived class constructor"<<endl;

	}
	~Derived() { 

		cout<<"In derived class destructore"<<endl;
		delete[] data;
	}
};

int main() {
	Base* obj = new Derived();
	delete obj;

	// Derived* d1 = new Base();
	//delete d1;

	return 0;
}

