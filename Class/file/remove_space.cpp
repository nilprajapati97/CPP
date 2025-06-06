#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

main()
{
  char a[100]={},ch;
  int i=0,j=0,k=0;

  fstream fout;

  fout.open("new",ios::out|ios::in);

  while(!fout.eof())
    a[i++]= fout.get();
   
  for(i=0;a[i];i++)
    cout<<a[i];
    cout<<endl;
  
 for(i=0;a[i];i++)
   {
      if(a[i]==a[i+1]  && a[i]==' ') 
         {
            for(j=i;a[j];j++)
              a[j]=a[j+1];
               i--; 
         }
   }                                                    

  for(i=0;a[i];i++)
    cout<<a[i];
    cout<<endl;

  fout.close();

  fout.open("new",ios::out|ios::in|ios::trunc);
   
       for(i=0;a[i];i++)
         fout.put(a[i]);          
}

