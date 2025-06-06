#include<iostream>
using namespace std;
main()
{
 int x=10;
 int z=20;
 
 int *p=&x;
 int &y=x;

  cout<<"The values..."<<endl;
  cout<<"x="<<x<<endl<<"y="<<y<<endl<<"*p="<<*p<<endl<<"p="<<p<<endl;
 
  
}
