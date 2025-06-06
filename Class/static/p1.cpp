#include<iostream>
using namespace std;

class A
{
  private: int x;
           static int y;
  
  public: void set()
		{
                  x=10;
 		}
};

main()
{
  A a1;
 
  cout<<sizeof(a1)<<endl;

}
