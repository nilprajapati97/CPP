#include<iostream>
using namespace std;


main()
{
  int **p,**q,**r,i,j,k;

  p=new int*[3];
  for(i=0;i<3;i++)
  p[i]=new int[3];


  q=new int*[3];
  for(i=0;i<3;i++)
  q[i]=new int[3];

  
  r=new int*[3];
  for(i=0;i<3;i++)
  r[i]=new int[3];
  
  
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      cin>>p[i][j];

  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      cin>>q[i][j];

  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      for(k=0;k<3;k++)
       r[i][j]+=(p[j][k]*q[k][j]);


 cout<<"result is"<<endl;


  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      cout<<r[i][j]<<endl;
    
}
