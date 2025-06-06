#include<iostream>
using namespace std;

class A
{
  private:float a;
          float b;

  public:A(float i,float j)
       {
         a=i;
	 b=j;
       }

/* Imp note:- operator  conversiontype()  //conversiontype= in which type u convert is int y so take int

  1>it must be a member function
  2>It should not take any argument
  3>It bshould not return type but should return value
*/
 
  operator int()
  {
     return (a+b);
  }

};

main()
{
  A a1(12.3,36.7);

  int y;
  
  y=a1;

  cout<<"y="<<y<<endl;
}
