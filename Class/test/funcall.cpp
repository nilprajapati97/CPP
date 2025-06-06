#include<iostream>
using  namespace std;

class A
{
  private:int x;

  public: void set()
	 {
           cout<<"Enter the value of x"<<endl;
           cin>>x;
         }

         void display()
	{
          cout<<x<<endl;
	}

 	void operator ()(int a)
         {
            set();
            display();

           x=x+a;
           display(); 
         }

};

main()
{
  A a1;
  a1(5);
}

