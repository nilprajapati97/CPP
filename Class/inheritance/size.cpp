#include<iostream>
using namespace std;

class A
{
	private: int x;
};

class B:public A
{
	private:int a;
		int y;
};

main()
{
	A a1;
	B b1;

	cout<<sizeof(a1)<<endl;
	cout<<sizeof(b1)<<endl;
}
