#include<iostream>
using namespace std;


class A
{
  private:int x;
          int y;

  public:void set()
	{
          x=10;
          y=20;
        }

        void print()
	{
          cout<<x<<endl<<y<<endl;
	}
 
friend void outside(A &);
};

void outside(A &a)
{
  a.x=100;
  a.y=200;
}

main()
{
  A a1;
  
  a1.set();
  a1.print();
 
  outside(a1);
  a1.print();   
}
