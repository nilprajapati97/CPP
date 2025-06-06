/* Write a C++ program to sort the given five names from the keyboard and print it in the sorted order. (Use C++'s DMA).
*/

#include<iostream>
#include<string.h>
using namespace std;

class A
{
  private:char **arr,temp[20];
          int i,j;

  public:void set()
          {
             arr=new char*[5];

             for(i=0;i<5;i++)
               arr[i]=new char[10];

            cout<<"enter the name"<<endl;
             for(i=0;i<5;i++)
               cin>>arr[i]; 
          }
  
          void get()
	  {

             for(i=0;i<5;i++)
             cout<<arr[i]<<endl;  
	  }

         void sort()
          {
             for(i=0;i<5-1;i++)
              {
                for(j=i;j<5;j++)
                 {
                  if(strcmp(arr[i],arr[j])==1)
                    {
                        strcpy(temp,arr[i]);
                        strcpy(arr[i],arr[j]);
                        strcpy(arr[j],temp); 
                    }
                   
                 }
          }
                 }

};
	 
main()
{
 A a1;

 a1.set();

 cout<<"before sort"<<endl; 
 a1.get(); 
 
 a1.sort();
 cout<<"before sort"<<endl; 
 a1.get(); 
}
 


