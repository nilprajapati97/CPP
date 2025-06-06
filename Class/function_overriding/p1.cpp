#include<iostream>
using namespace std;

class A
{
  private: int x,y;

  public:void display()
	{
          cout<<"In base class"<<endl;
	}
};

class B:public A
{
  private:int a,c;
  public:void display()
	{
          cout<<"in derived class display function"<<endl;
	}
};

main()
{
  A a1;
  B b1;

  b1.display();
}
