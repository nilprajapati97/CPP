//solution of p1.cpp

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

void outsidefun(A a)
{
  cout<<a.x<<endl<<a.y<<endl;
}

main()
{
  A a1;
 
  a1.set_data(10,20);
  outsidefun(a1);
}
