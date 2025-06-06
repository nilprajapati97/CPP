#include<iostream>
using namespace std;

class A
{
  private:int x;

  friend istream& operator >>(istream &,A a);	
};

 istream& operator >>(istream &in,A a)	
  {
     cout<<"Enter the value"<<endl;
     in>>a.x;
     return in;   
  }

main()
{
  A a1;

  cin>>a1; 
 
}
