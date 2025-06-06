#include<iostream>
using namespace std;

void display(int,int=40);//here provide int=40 is a default argument
void display(int);

main()
{
  display(20);
}

void display(int a,int b)
{
  cout<<a<<endl<<b<<endl;
}


void display(int a)
{
  cout<<a<<endl;
}
