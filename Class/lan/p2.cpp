/* C++ program to create a class complex with real and imaginary parts perform addition and subtraction of
 two complex objects.
*/

#include<iostream>
using namespace std;

class complax
{
  private:int real;
          int imagnary;

  public:void setdata()
 	 {
           cout<<"Enter the real data"<<endl;
	   cin>>real;
   
           cout<<"Enter the imagnary data"<<endl;
	   cin>>imagnary;
	 }

       void getdata()
 	 {
           cout<<"The real data"<<endl;
	   cout<<"real="<<real<<endl;
   
           cout<<"The imagnary data"<<endl;
	   cout<<"imagnary="<<imagnary<<endl;
	 }

friend void add(complax,complax);
friend void sub(complax,complax); 
};

void add(complax a,complax b)
{
   cout<<"real part"<<a.real + b.real <<endl;
   cout<<"imagnary part"<<a.imagnary + b.imagnary <<endl;
}

void sub(complax a,complax b)
{
   cout<<"real part"<<a.real - b.real <<endl;
   cout<<"imagnary part"<<a.imagnary - b.imagnary <<endl;
}

main()
{
  complax a1,a2;
  
  a1.setdata();
  a1.getdata();
  a2.setdata();
  a2.getdata();

  add(a1,a2);
  sub(a1,a2);
}

