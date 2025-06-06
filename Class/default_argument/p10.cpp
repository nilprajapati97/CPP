#include<iostream>
using namespace std;

void display(int);
void display(int &);

main()
{
  int k=100; 
  display(k);
}

void display(int a)
{
  cout<<a<<endl;
}


void display(int &a)
{
  cout<<a<<endl;
}
