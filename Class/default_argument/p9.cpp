#include<iostream>
using namespace std;

void display(int);
void display(int &);

main()
{
  display(100);
}

void display(int a)
{
  cout<<a<<endl;
}


void display(int &a)
{
  cout<<a<<endl;
}
