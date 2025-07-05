
#include<iostream>
using namespace std;

class A
{
   //  VTABLE
   //    f2()  ->  Class A
   //    f3()  ->  Class A
   //    f4()  ->  Class A 
public :
        void f1()   
        {
           cout << "In class A : in function f1 "<<endl;
        }
        
        virtual void f2()  
        {
           cout << "In class A : in function f2 "<<endl;
        }
        
        virtual void f3()   
        {
           cout << "In class A : in function f3 "<<endl;
        }
        
        virtual  void f4()  
        {
           cout << "In class A : in function f4 "<<endl;
        }
};
class B : public A
{
   //  VTABLE
   //    f2()  ->  Class B
   //    f3()  ->  Class A
   //    f4()  ->  Class A 
public:
   
   void f1() 
   {
        cout << "In class B : in function f1 "<<endl;
	}
   
   void f2() 
	{
	  cout << "In class B : in function f2 "<<endl;
	}
   
   void f4(int x) // function overridding
	{
	  cout << "In class B : in function f4 "<<endl;
	}

};

int main()
{
/* 
    A *p,o1;
    
    p=&o1;
    
    p->f1();    //  EB;    In class A : in function f1
    p->f2();    //  LB;    In class A : in function f2
    p->f3();    //  LB;    In class A : in function f3
    p->f4();    //  LB;    In class A : in function f4
    p->f4(5);   //  EB;   //error: no matching function for call to ‘A::f4(int)’
*/


    A *p;
    B o2;

    p = &o2;

    p->f1();    //  EB;    In class A : in function f1
    p->f2();    //  LB;    In class B : in function f2
    p->f3();    //  LB;    In class A : in function f3 there is no f3() in child
    p->f4();    //  LB;    In class A : in function f4
//    p->f4(5);   //  EB;   //error: no matching function for call to ‘A::f4(int)’


 return 0;
}


/*

 * */