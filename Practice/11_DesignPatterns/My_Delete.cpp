#include<iostream>
using namespace std;

class Product{

	public:
		virtual void use()=0;
		virtual ~Product() = default;

};
class Car:public Product
{
	void use () override
	{
	cout<< "using Car Product"<<endl;
	}
};
class Bike:public Product
{
	void use () override
	{
	cout<< "using Bike Product"<<endl;
	}
};

class Factory
{
public:
	virtual Product* CreateProduct()=0;
        virtual ~Factory()=default;
};
class CarFactory : public Factory
{
	public:
	Product* CreateProduct() override
	{
		cout<<"Uisng CarFactory"<<endl;
		return new Car();
		// return new Bike(); // Uncomment to use Bike instead of Car
	}
};
class BikeFactory : public Factory
{
	public:
	Product* CreateProduct() override
	{
		cout<<"Uisng BikeFactory"<<endl;
		return new Bike();
		// return new Car(); // Uncomment to use Car instead of Bike
	}
};

int main()
{
   Factory* carFactory = new CarFactory();
   Product* car = carFactory->CreateProduct(); 
   car->use();


   Factory* bikeFactory = new BikeFactory();
   Product* bike = bikeFactory->CreateProduct(); 
   bike->use();

   return 0;
}
