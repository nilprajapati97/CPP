#include<iostream>
using namespace std;

class A
{
  private:int x;
 	  int y;

  public:void set_data(int a,int b)
          {
	    x=a;
            y=b;	
	  } 
};

main()
{
 A a1;
 
 a1.set_data(10,20);

}
