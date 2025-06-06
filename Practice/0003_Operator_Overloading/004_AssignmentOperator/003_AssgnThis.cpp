#include<iostream>
using namespace std;

class A
{
  private: int x;
    
  public:A()
	{
    x=100;
  } 
   
  void display()
	{
    cout<<x<<endl;
	}
};

int main()
{
  A a1;
 int y=500;
  
 a1=y;
 
 a1.display();  
 return 0;
}