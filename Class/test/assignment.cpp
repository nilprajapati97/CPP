#include<iostream>
using namespace std;

class A
{
  private:int x;
   
  public: void setdata()
 	{
          x=10;
        }


   	void display()
	{
          cout<<x<<endl;
        }
};

main()
{
  A a1,a2;

  a1.setdata();
  a2=a1; 
  a2.display(); 

}

