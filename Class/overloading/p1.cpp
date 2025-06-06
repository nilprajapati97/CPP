#include<iostream>
using namespace std;

void display(int);
void display(char);

main()
{
  display(10);
  display('A');
}

void display(int a)
{
  cout<<a<<endl;
}

void display(char ch)
{
  cout<<ch<<endl;
}
