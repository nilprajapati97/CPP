// c3=c1-20+c2+100+c3+15-25;

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
      friend  complx operator+(complx ,int );
      friend  complx operator+(int ,complx );      
      friend  complx operator-(complx ,int );
      friend  complx operator-(int ,complx );      

};

        complx operator+(complx d,complx c)
         {
           complx temp;
           temp.real=d.real+c.real;
           temp.img=d.img+c.img;

           return temp;
         }
      
       complx operator+(complx c,int i)
         {
           complx temp;
           temp.real=c.real+i;
           temp.img=c.img+i;

           return temp;
         }

        complx operator+(int i,complx c)
         {
           complx temp;
           temp.real=c.real+i;
           temp.img=c.img+i;

           return temp;
         }

       complx operator-(complx c,int i)
         {
           complx temp;
           temp.real=c.real-i;
           temp.img=c.img-i;

           return temp;
         }

        complx operator-(int i,complx c)
         {
           complx temp;
           temp.real=i-c.real;
           temp.img=i-c.img;

           return temp;
         }

main()
{
  complx c1(12.3,23.5),c2(1.3,3.8),c3(12.5,3.6),c4;

  c4=c1-20+c2+100+c3+15-25;  //c1.operator+(c2,100)  here two operator is overloaded

  c4.display();    
}
