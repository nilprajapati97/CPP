#include<iostream>
using namespace std;

void fun(int &,int &);

main()
{
   int x=10;
   int y=20;

   cout<<"before function call"<<endl;
   cout<<x<<endl<<y<<endl;

      
   fun(x,y);

   cout<<"after function call"<<endl;
   cout<<x<<endl<<y<<endl;
}

void fun(int &x,int &y)
{
  x=x+1;
  y=y+1;
}
