#include<iostream>
using namespace std;

void fun(float);
void fun(double);

main()
{
  fun(2.3);
}

void fun(float k)
{
  cout<<k<<endl; 
}


void fun(double p)
{
  cout<<p<<endl; 
}


