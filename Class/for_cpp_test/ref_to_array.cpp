#include<iostream>
using namespace std;

main()
{
  int i;
  int a[5]={1,2,3,4,5};

  int (&b)[5]=a;


  for(i=0;i<5;i++)
  cout<<b[i]<<endl;
}
