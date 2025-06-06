#include<iostream>
using namespace std;

class add
{
  int m,n;

  public:add()
         {
           m=0;
	   n=0;
	 } 

         add(int a,int b)
          {
            m=a;
 	    n=b;
          } 

         add(add &i)
          {
            m=i.m;
 	    n=i.n;
          } 
         
         void display()
          {
            cout<<m<<endl<<n<<endl;
          }


};

main()
{
  add a1;
  a1.display();
   
  add a2(10,20);
  a2.display();

  add a3(a2);
  a3.display();
}
