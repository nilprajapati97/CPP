#include<iostream>
using namespace std;

class A
{
 private:int x,y;

 public:void setbase()
 	{
           x=10;  
           y=20;
	}
};

class B:private A
{
  private:int a,c;

  public:void setderived()
         {
           cout<<"In derived setfun..\n"<<endl;
         }
};

main()
{
  A a1;
  B b1;

  b1.setderived();
  b1.setbase();
}
