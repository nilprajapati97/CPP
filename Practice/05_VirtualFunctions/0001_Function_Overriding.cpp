#include<iostream>
using namespace std;

class A
{


public :
    void f1()
	{
	  cout << "In class A : in function f1 "<<endl;
	}
    
	void f2()
	{
	  cout << "In class A : in function f2 "<<endl;
	}
    
	void f3()
	{
	  cout << "In class A : in function f3 "<<endl;
	}
};
class B : public A
{

public:
    void f1() // function overridding
	{
	  cout << "In class B : in function f1 "<<endl;
	}
    
	void f2(int x) // function hiding
	{
	  cout << "In class B : in function f2 "<<endl;
	}
};

int main()
{
  B obj;
  obj.f1();
  //obj.f2();
  obj.f2(4);
  obj.f3();
}
/*
 * obj.f1() -->  Function here consider which type of object called this function. So here Class B.
 * 		 It will search f1() in class B and calls that function. Bassed on type
 *
 * obj.f2() -->  Here f2 based by class B and in class B there is function to search and 
 *               if function name matches then it will not go to parent class.
 *               but it will give error here arguments not maches 
 * obj.f3() -->  here function f3() called by class B and in class b searchs function name,
 *               but function not there so It will look for parent class and calls parent class f3()
 *              
 *For function overloading 
 *	f2(), f(int) should be in same class not in parent and child class
 * 
 * For function Overloading all the version of functions should be in same class or same scope
 *
 *
 *
 *
 * */

