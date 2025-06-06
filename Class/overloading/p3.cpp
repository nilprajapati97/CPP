#include<iostream>
using namespace std;

void display(int,char);
void display(char,int);

main()
{
   display(10,'b');
   display('c',20);
}

void display(int a,char b)
{
  cout<<a<<" "<<b<<endl;
}

void display(char a,int b)
{
  cout<<a<<" "<<b<<endl;
}
