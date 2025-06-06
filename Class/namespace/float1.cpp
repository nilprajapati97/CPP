#include<iostream>
using namespace std;

void fun1(float);
void fun(double);

main()
{
  fun(2.3);
  fun1(2.3);
}

void fun1(float k)
{
  cout<<k<<endl; 
}


void fun(double p)
{
  cout<<p<<endl; 
}


