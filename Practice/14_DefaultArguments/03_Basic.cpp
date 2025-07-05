#include<iostream>
using namespace std;

void display(int=30,int);//here provide int=30 is a default argument

main()
{
  display(10);
}

void display(int a,int b)
{
  cout<<a<<endl<<b<<endl;
}
