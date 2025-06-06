#include<iostream>
using namespace std;

main()
{
  int *p,i;

  p=new int[5];//20 bytr memory allocated
   
  for(i=0;i<5;i++)
    cin>>p[i];

  for(i=0;i<5;i++)
    cout<<p[i]<<endl;
}
