#include<iostream>
using namespace std;

class A
{

public :
     void f1()  // -->> compile time binding
    //virtual void f1()  // run time binding
    {
      cout << "In class A : in function f1 "<<endl;
    }


};
class B : public A
{

public:

   void f1() // function overridding
	{
	  cout << "In class B : in function f1 "<<endl;
	}

};

int main()
{
 
    A *p,o1;
    B o2;
    p=&o2;
    p->f1(); //A;  when virtual -->> //B

 return 0;
}
/*
Output
==============
In class A : in function f1 

*/

/*
 * Here we have created pointer of base class.
 * and assign addrresss of child class.
 * When function calls , it will calls parent class f1() function. But we assigned child class address to pointer.add_pointer
 * It should call chil class function f1(); Thats call Early binding.
 * In ealy binding pointer depend on its type.
 * 
 * To overcome early binding we need to use run time binding and that we can achive through Vertual function.
 *  1. compile time binding   // Its depend on type of pointer
 *      void f1() -->> declare in class A 
 *       p->f1();   //A;
 *
 *  2. compile time binding  // Its depend on content of pointer
 *      virtual void f1() -->> declare in class A 
 *       p->f1();   //B;  by late binding we can achieve function overriding
 * */

