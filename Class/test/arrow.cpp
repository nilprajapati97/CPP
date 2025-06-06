#include<iostream>
using namespace std;

class A
{
   int x;
  
  public:void set()
	{
           x=10;
	} 

        void display()
	{
           cout<<x<<endl; 
        }

       A* operator->()
        {
          return this;
        }
      
};

main()
{
  A a1;
  a1.set();
  a1->display();
}
