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


     friend void operator ++(A &);
};

		void operator ++(A &a)
		{
		       cout<<"In operator function.."<<endl;
		       a.x=++a.x;
		}
main()
{
	A a1;
	a1.display();

	++a1;  //operator ++(a1);

	a1.display();

}


