#include<iostream>
using namespace std;

class A
{
  private: int x;
           static int y;
  
  public: void set()
		{
                  x=200;
                  y=100;
 		}      

          void get()
                {
                  cout<<"x="<<x<<"y="<<y<<endl; 
                }           

};

int A::y;

main()
{
  A a1,a2;
   
  a1.set();
  a1.get(); 
}


