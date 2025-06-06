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

friend complx operator+(complx , complx);       
};


        complx operator+(complx c, complx d)
         {
           complx temp;
           temp.real=c.real+d.real;
           temp.img=c.img+d.img;

           return temp;
         }


main()
{
  complx c1(12.3,23.5),c2(1.3,3.8),c3;

  c3=c1+c2;  //operator+(c1)(c2);

  c3.display();    
}
