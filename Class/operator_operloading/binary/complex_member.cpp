#include<iostream>
using namespace std;

class complx
{
  private:float real;
	  float img;

  public:
         complx(float a,float b)
          {
            real=a;
	    img=b;
 	  }

        void display() 
         {
	 cout<<"real="<<real<<endl<<"img="<<img<<endl;
         }

         complx()
         {
           //for c3;
         }


        complx operator+(complx c)
         {
           complx temp;
           temp.real=real+c.real;
           temp.img=img+c.img;

           return temp;
         }

       
};

main()
{
  complx c1(12.3,23.5),c2(1.3,3.8),c3;

  c3=c1+c2;  //c1.operator+(c2)  here two operator is overloaded

  c3.display();    
}
