#include<iostream>
using namespace std;

class A
{
	private:int x;

	public:A()
	       {
		       x=10;
	       }

	       friend void operator <<(ostream &,A);
};

void operator << (ostream &out,A a)
{
	out<<a.x<<endl;
}

main()
{
	A a1;

	cout<<a1<<endl;  // opeartor(cout,a1)
}

