#include<iostream>
using namespace std;

class A
{
	private:
		int  a;
		int  b;

	public:
		void SetData(int x, int y)
		{
			cout<<"in display function"<<endl;
			a=x;
			b=y;

		}	

		void display()
		{
			cout<<"in display function"<<endl;
			cout<<"a="<<a<<endl<<"b="<<b<<endl;
		} 

		A operator +(A c)
		{
			cout<<"in operator + function"<<endl;
			c.a= a +c.a;
			c.b= b +c.b;
			return (c);
		}
};

int main()
{

	A c1, c2,c3;

	c1.SetData(10,20);
	c2.SetData(30,40);

	cout<<"Output of C1"<<endl;
	c1.display();    

	cout<<"Output of C2"<<endl;
	c2.display();    

	c3= c1+c2;  // c.operator+ (c2)

	cout<<"Output of C3"<<endl;
	c3.display(); 
	return 0;
}

