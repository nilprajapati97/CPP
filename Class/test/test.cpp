#include<iostream>
using namespace std;
class A
{
	protected:
	int x,y;

	public:
	void display()
	{
		cout << "x = "<< x << " y = "<< y << endl;		
	}
};
class B : public A
{
	public:
	void setdata()
	{
		x = 10, y = 20;
	}
};
int main()
{
	B obj;
	obj.setdata();
	obj.display();
}
