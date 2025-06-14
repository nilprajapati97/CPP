#include<iostream>
using namespace std;
/*

Constructore which does not accept any params called defalt constructure
 If Explicitily constructore not cALLED THAN dEAFAULT CONSTRUCTOR USED.


*/

class A
{
  int x;
 	int y;
 public:
  A():x(10) ,y(20)
  {
    cout<< "01.Constructor" <<endl;  
  }

  A(int a) :x(a),y(100)
  {
    cout<< "02.0 Parameterized Constructor" <<endl;  
  }

  A(int a ,int b):x(a),y(b)
  {
    cout<< "02.1 Parameterized Constructor" <<endl;  
  }

  A(A &obj):x(obj.x),y(obj.y)
  {
    cout<< "03. Copy Constructor" <<endl;  
  }

  void print() const
  {
    cout <<"X="<<x<<endl<<"Y="<<y<<endl;
  
  }
};

int main()
{
 A obj1 ,obj2(11,22),obj3 = obj1;
 
 obj1.print();
 obj2.print();
 obj3.print();

}
