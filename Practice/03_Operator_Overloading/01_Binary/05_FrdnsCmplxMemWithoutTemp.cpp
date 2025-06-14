#include<iostream>
using namespace std;

class A
{
  private:float real;
	  float img;

  public:
         A(float a,float b)
          {
            real=a;
	    img=b;
 	  }

        void display() 
         {
	 cout<<"real="<<real<<endl<<"img="<<img<<endl;
         }

         A()
         {
           //for c3;
         }

friend A operator+(A , A);       
};

A operator+(A c, A d)
{
     
    c.real=c.real+d.real;
    c.img=c.img+d.img;

    return c;
}

int main()
{
  A c1(12.3,23.5),c2(1.3,3.8),c3;

  c3=c1+c2;  //operator+(c1)(c2);

  c3.display();

  return 0;    
}