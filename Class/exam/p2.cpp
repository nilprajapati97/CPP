#include<iostream>
using namespace std;

main()
{
  int x=10;
  int y=20;
  int &r=x;
  int &k=y;

  r=k;
  
 cout<<r<<k<<x<<y<<endl;
}
