#include<iostream>
using namespace std;

class A
{
  private:int x;

  public:A(int k)
	{
          x=k;
          cout<<x<<endl; 
	}
   
        A()
        { 

        }
};

main()
{
 int y=200;

 A a1;
 
 a1=y;

}
