//conversion take source side so use operator function

#include<iostream>
using namespace std;

class B;

class A
{
	private: int x;
		 int y;

	public:A()
	       {
		       x=10;
		       y=20;
	       }

	       operator B();
};

class B
{
	private: int i;
		 int j;

	public:B()
	       {

	       }

	       void display()
	       {
		       cout<<"i="<<i<<"j="<<j<<endl;    
	       }     

	       friend A::operator B();
};

A::operator B()
{
	B temp;
	temp.i=x;
	temp.j=y; 

	return temp;
}

main()
{
	A a1;
	B b1;

	b1=a1;

	b1.display();
}

