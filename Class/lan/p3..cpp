/*write a C++ program to swap two variables using function. (Don't use Pointers).*/

#include<iostream>
using namespace std;

class A
 {
   private:int x,y;

   public:void set()
	  {
            x=10;
	    y=20;
	  } 

          void get()
          {
            cout<<x<<endl<<y<<endl;
          }

          void swap()
          {
             int z;
 	     z=x;
	     x=y;
	     y=z;
          } 
};

main()
{
  A a1;
  a1.set();

  cout<<"before swap"<<endl;
  a1.get();

  a1.swap(); 
  cout<<"after swap"<<endl;
  a1.get();
}  




