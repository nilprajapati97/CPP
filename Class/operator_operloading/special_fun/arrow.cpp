//arrow operator overload 

#include<iostream>
using namespace std;

class A
{
  private:int x;
          int y; 
 
  public:A()
	{
          x=20;
          y=30;
	}  
      
         void display()
	{
          cout<<x<<endl<<y<<endl;
	}
     
       A* operator->()
        {
          return this;
        }
};

main()
{
 A a1;
 
 a1->display();
}


