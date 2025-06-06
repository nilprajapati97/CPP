#include<iostream>
using namespace std;

void display(int=50,int=40);//here provide int=30 is a default argument

main()
{
  display();
}

void display(int a,int b)
{
  cout<<a<<endl<<b<<endl;
}
