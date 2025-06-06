#include<iostream>
using namespace std;

class A
{
  private: int inc1;
	   int inc2;

  public: void set()
	{
          cout<<"Enter income1 and income2"<<endl;
          cin>>inc1;
          cin>>inc2; 
 	}	

        void display()
        {
          cout<<inc1<<endl;
          cout<<inc2<<endl;
        }

friend class B;
};


class B
{
  public: void get(A a)
         {
          cout<<"class A private data in class B"<<endl;  		
          cout<<a.inc1<<endl;
          cout<<a.inc2<<endl;
         }
		
	void modify(A &a1)
         {
           a1.inc1=a1.inc1+100;
           a1.inc2=a1.inc2+200;           
         }	
};

main()
{
  A a1;
  B b1;

 a1.set();
 a1.display();

 b1.get(a1);
 b1.modify(a1);

 a1.display();    
}


