#include<iostream>
using namespace std;

class Product {
   public: 
	   virtual void use() =0;
	   virtual ~Product() = default;
};
class CarProduct:public Product {
   public: 
	   void use() override 
	   {
	   	cout<<"In CarProduct ..."<<endl;
	   }
};
class BikeProduct:public Product {
   public: 
	   void use() override 
	   {
	   	cout<<"In BikeProduct ..."<<endl;
	   }
};

class Factory {
  public : 
	  virtual Product* createProduct ()= 0;
	  virtual ~Factory() = default;
};
class CarFactory:public Factory {
  public : 
	  Product* createProduct () override 
	  {
	  	return new CarProduct();
	  }
};
class BikeFactory:public Factory {
  public : 
	  Product* createProduct () override 
	  {
	  	return new BikeProduct();
	  }
};

int main()
{
   Factory* carFactory = new CarFactory();
   Product* carProduct = carFactory->createProduct();
   carProduct->use();

   Factory* bikeFactory = new BikeFactory();
   Product* bikeProduct = bikeFactory->createProduct();
   bikeProduct->use();

}


