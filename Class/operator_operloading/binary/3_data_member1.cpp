// c4=c1+c2+c3;

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
           //for c4;
         }



      friend  complx operator+(complx ,complx);
       
};

        complx operator+(complx d,complx c)
         {
           complx temp;
           temp.real=d.real+c.real;
           temp.img=d.img+c.img;

           return temp;
         }

main()
{
  complx c1(12.3,23.5),c2(1.3,3.8),c3(1.3,5.8),c4;

  c4=c1+c2+c3;  //c1.operator+(c2,100)  here two operator is overloaded

  c4.display();    
}
