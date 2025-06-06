#include<iostream>
using namespace std;
main()
{
  int x=10;

  int &y=x;
  int &z=y;

  cout<<"The values..."<<endl;
  cout<<"x="<<x<<endl<<"y="<<y<<endl<<"z="<<z<<endl;
 
  cout<<"The adresses..."<<endl;
  cout<<"&x="<<&x<<endl<<"&y="<<&y<<endl<<"&z="<<&z<<endl;
   
}
