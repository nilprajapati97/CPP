#include<iostream>
using namespace std;

class A
{
 public: int x;
 	 int y;

 void set_data(int a,int b)
   	{
         x=a;
	 y=b;
        }
 
  void print()
   {
  	cout<<x<<endl<<y<<endl;
   }

};

void outsidefun(A a)
{
  a.x=200;
  a.y=300;
}

main()
{
  A a1;
 
  a1.set_data(10,20);
  outsidefun(a1);
  a1.print();
}
