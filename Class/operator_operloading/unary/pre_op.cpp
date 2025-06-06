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

		void operator ++()
		{
			cout<<"In operator function.."<<endl;
			x=++x;
		}
};

main()
{
	A a1;
	a1.display();

	++a1;  //a1.operator++();

	a1.display();

}


