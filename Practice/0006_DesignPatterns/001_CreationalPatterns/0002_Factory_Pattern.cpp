/*
  2. Factory Pattern
 	Provides an interface for creating objects in a superclass but allows subclasses to alter the type of objects that will be created.
   
  */

// Product Interface

#include<iostream>
using namespace std;

class Product
{

	public: 
		virtual void use() = 0;
		
};

//Concrete Products
class ConcreteProductA : public Product
{
	public :
		void use() override 
		{
			cout<< "Using Product A" <<endl;
		
		}
};

class ConcreteProductB : public Product
{
	public :
		void use() override 
		{
			cout<< "Using Product B" <<endl;
		
		}
};

// factory Class
class Factory
{
	public : 
	    static Product* createProduct(char type)
	    {
		    if (type =='A')
			    return new ConcreteProductA();
	    
		    if (type =='B')
			    return new ConcreteProductB();
	             
		    return nullptr;
	    
	    }
};

int main()
{
	Product* p1 = Factory::createProduct('A');
	if(p1) 
		p1->use();

	Product* p2 = Factory::createProduct('B');
	if(p2) 
		p2->use();

	delete p1;
	delete p2;

	return 0;



}
