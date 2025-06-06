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
};

void outsidefun()
{
  cout<<x<<endl<<y<<endl;
}

main()
{
  A a1;
 
  a1.set_data();
  outsidefun();
}
