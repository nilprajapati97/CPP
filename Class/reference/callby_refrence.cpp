#include<iostream>
using namespace std;

void fun(int&,int&);
main()
{
 int x=10;
 int y=20;

 cout<<"before function call.."<<endl;
 cout<<"x="<<x<<endl<<"y="<<y<<endl;

 fun(x,y);
 
 cout<<"after function call.."<<endl;
 cout<<"x="<<x<<endl<<"y="<<y<<endl;
 
}

void fun(int &a,int &b)
{
  a=a+1;
  b=b+1;
}
