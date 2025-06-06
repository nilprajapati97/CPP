#include<iostream>
using namespace std;

class A
{
  private: int x;
           static int y;
  
  public: void set()
		{
                  x=10;
                  y=20;
 		}                 
};

main()
{
  A a1,a2;
   
  a1.set();
}
