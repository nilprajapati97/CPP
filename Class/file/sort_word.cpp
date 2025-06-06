#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

main()
{
  char a[100]={},b[100]={},ch;
  int i=0,j=0,k=0;
  fstream fout;

  fout.open("new",ios::out|ios::in);
/*
  while(fout>>a[i++]);

  for(i=0;a[i];i++)
    cout<<a[i];

  cout<<endl; 


  while(fout>>ch)
  {
    fout.seekg(-1,ios::cur);
    fout.get(ch);
    a[i++]=ch;
  }
*/
   while(fout.getline(a,100))
    {
       if(fout.eof())
          break;  
     strcpy(b,a);
    }

  
  for(i=0;b[i];i++)
    cout<<b[i];
    cout<<endl;


        k=0;
        for(i=0; ;i++) 
          {
             if(b[i]==' ' || b[i]=='\0')
              {
                for(j=i-1;k<j;k++,j--)
                  {
                   
                    temp=b[j];
                    b[j]=b[k];
                    b[k]=temp; 
                  }
                k=i+1;
               }

  for(i=0;b[i];i++)
    cout<<b[i];
    cout<<endl;

  fout.close();

  fout.open("new",ios::out|ios::in|ios::trunc);
 
  for(i=0;b[i];i++)
    fout<<b[i];
   
}

