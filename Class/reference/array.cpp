#include<iostream>
using namespace std;
main()
{
 int i;
 int a[5]={1,2,3,4,5};
 int (&b)[5]=a;//b is a refrence to a array a it contain 5 integer 

 for(i=0;i<5;i++)
  {
    cout<<b[i]<<endl;
  } 

}
