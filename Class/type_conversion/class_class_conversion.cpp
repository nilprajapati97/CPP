#include<iostream>
using namespace std;

class A
{
  private: int x;
           int y;

  public:A()
 	{
          x=10;
          y=20;
        }
   
        int get_x()
	{
	 return x;
	}
      
        int get_y()
	{
	 return y;
	}
};

class B
{
  private: int i;
	   int j;
 
 public:B()
	{

        }

       B(A obj)
       {
          i=obj.get_x();
	  j=obj.get_y();	   
       }       
  
      void display()
	{
          cout<<"i="<<i<<"j="<<j<<endl;    
	}     
};

main()
{
  A a1;
  B b1;

  b1=a1;

  b1.display();
}

