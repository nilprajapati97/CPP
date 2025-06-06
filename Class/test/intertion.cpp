#include<iostream>
using namespace std;

class A
{
  private:int x;

  public:A()
	{
          x=10;
	}
    
  friend ostream& operator <<(ostream &,A); 
};

ostream& operator <<(ostream &out,A a)
{
   out<<a.x;
   return out;
}

main()
{
  A a1;
  
  cout<<a1<<endl;
  
}
