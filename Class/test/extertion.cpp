#include<iostream>
using namespace std;

class A
{
  int x;

  public:A()
	{
	 x=10;
	}

 friend istream& operator >>(istream &,A);
};

istream& operator>>(istream &in,A a1)
{
  in>>a1.x;
  return in;
}

main()
{
  A a1;
 
  cin>>a1;

  
}

