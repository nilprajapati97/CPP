#include<iostream>
using namespace std;

main()
{ 
  int x=10;
  int *p=&x;
  int *(&y)=p;
  
  cout<<"values are..."<<endl;
  cout<<"x="<<x<<endl<<"*p="<<*p<<endl<<"*y="<<*y<<endl;


  cout<<"address are..."<<endl;
  cout<<"&x="<<&x<<endl<<"p="<<p<<endl<<"y="<<y<<endl;

  cout<<"&p="<<&p<<endl<<"&y="<<&y<<endl;
}
