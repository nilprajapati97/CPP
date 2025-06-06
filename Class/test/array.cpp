#include<iostream>
using namespace std;

class A
{
  private:int y;
         int a[5];

  public:void setdata()
	 {
           for(int i=0;i<5;i++)
              a[i]=10+i;
         } 

 int operator [](int k)
  {
    return a[k];
  } 
};

main()
{
   A a1;
   a1.setdata();
   int y=a1[2];
  
  cout<<y<<endl; 
}
