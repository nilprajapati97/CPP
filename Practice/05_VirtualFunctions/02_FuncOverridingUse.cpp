
#include<iostream>
using namespace std;

class Car
{


public :
    void shiftGear()
	{
	  cout << "In class A : in function shiftGear "<<endl;
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
class SportsCar : public Car
{

public:
       void gearChange()
	{
	  cout << "In class B : in function gearChange "<<endl;
	}

    
    void shiftGear()
	{
	  cout << "In class B : in function shiftGear "<<endl;
	}

	void f2(int x) // function hiding
	{
	  cout << "In class B : in function f2 "<<endl;
	}
};

int main()
{
  SportsCar obj;
  Car obj1;
  obj.shiftGear();
  obj1.shiftGear();
  obj.gearChange();
  return 0;
}
/*
Output
===============
In class B : in function shiftGear 
In class A : in function shiftGear 


*/



/*
 * Here sportsCar having functionality gear change 2 type gear change and shift gear.
 * But it wants only from child class.
 *
 *
 *
 * */

