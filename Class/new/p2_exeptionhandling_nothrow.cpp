#include<iostream>
using namespace std;

main()
{
 int *p;
 p=new(nothrow)int[900000000];
 cout<<*p<<endl;
}
