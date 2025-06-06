#include<iostream>
using namespace std;

main()
{
  int **a,**b,**c;
  int i,j,k;

  
  cout<<"Enter ther element of array1"<<endl;
  a=new int*[3];
  for(i=0;i<3;i++)
  a[i]=new int[3];


  cout<<"Enter the first array"<<endl;
  b=new int*[3];
  for(i=0;i<3;i++)
  b[i]=new int[3];


  c=new int*[3];
  for(i=0;i<3;i++)
  c[i]=new int[3];


   for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
        {
          cin>>a[i][j];
        }
    }

   cout<<endl;


  cout<<"Enter the second array"<<endl;
   for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
        {
          cin>>b[i][j];
        }
    }

   cout<<endl;

   for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
        {
        for(k=0;k<3;k++)
         {
          c[i][j]+=(a[j][k]*b[k][j]);          
         }
       }
    }


  cout<<"Result is"<<endl;
   for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
        {
          cout<<c[i][j]<<endl; 
        }
    }


   cout<<endl;
}
