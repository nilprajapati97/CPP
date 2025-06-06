#include<iostream>
using namespace std;

class add
{
  int m,n;

  public:add()
         {
           m=500;
	   n=9;
	 } 
  
         add(int a)
         {
	   m=a;
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
{/*
  add a1;
  a1.display();
   
  add a2(10,20);
  a2.display();

  add a3(a2);
  a3.display();
*/

  add a1(10),a2(20),a4;
  add a3(10,20);

  a1.display();
  a2.display();
  a3.display();
  a4.display();

}
