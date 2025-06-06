#include<iostream>
using namespace std;

class A
{
  private: int x,y;
  public: void setbase()
         {
          x=10;
	  y=20;
	 }

         void display()
	{
         cout<<"x="<<x<<endl<<"y="<<y<<endl;
	}
};

class B:public A
{
  private:int a,c;
  
  public:void setdrived()
        {
          cout<<"In derived setfunction.."<<endl;
        }
};

main()
{
 A a1;
 B b1;

 b1.setdrived();
// b1.setbase();
// b1.display();
// a1.display();
  
 a1.setbase();
 a1.display();

}
