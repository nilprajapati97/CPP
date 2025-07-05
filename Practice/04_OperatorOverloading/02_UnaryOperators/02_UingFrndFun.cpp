#include<iostream>
using namespace std;

class A
{
	private:int x;
	public: A()
		{
			x=10;
		}

		void display()
		{
			cout<<x<<endl;
		}

      friend void operator ++(A &);      //preincrement
      friend void operator ++(A &,int); //postincrement

};

void operator ++(A &a1) //for preincrement
{
	cout<<"In pre increment funtion.. "<<endl;
	a1.x=++a1.x;
}

void operator ++(A &a2,int)   //for post increament
{
	cout<<"In post increment function.."<<endl;
	a2.x=a2.x++;
}

main()
{
	A a1;
	a1.display();

	++a1;
	a1++;  //a1.operator++(int);

	a1.display();
}


