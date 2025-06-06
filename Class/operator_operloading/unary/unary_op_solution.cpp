#include<iostream>
using namespace std;

class A
{
  private:int x;
  public:A()
	{
         x=10;
        }
  
  void display()
	{
          cout<<x<<endl;
	}

  void operator -()
        {
          x=-x;
        }

};

main()
{
  A a1;
  
  a1.display();

  -a1;
  
  a1.display();
}
