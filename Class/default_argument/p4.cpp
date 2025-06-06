#include<iostream>
using namespace std;

void display(int,int=40);//here provide int=30 is a default argument

main()
{
  display(10,20);
}

void display(int a,int b)
{
  cout<<a<<endl<<b<<endl;
}
