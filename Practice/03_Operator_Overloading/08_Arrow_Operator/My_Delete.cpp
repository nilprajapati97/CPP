#include<iostream>
using namespace std;
class A{
	private : 
		int x;
		int y;
	public:
		A()
		{
			x=20;
			y=30;
		
		}

		void display()
		{
			cout<<"In display function"<<endl;
			cout<<"x ="<<x<<endl;
			cout<<"y ="<<y<<endl;
		
		}
	        
		A* operator->()
		{
			return this;
		
		}

};

int main()
{

	A a1;

	a1-> display();
}

