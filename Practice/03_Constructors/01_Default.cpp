#include <iostream>
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
  A()
  {
    cout << "01.Constructor" << endl;
    x = 10;
    y = 20;
  }

  A(int a)
  {
    cout << "02.0 Parameterized Constructor" << endl;
    x = a;
    y = 20;
  }

  A(int a, int b)
  {
    cout << "02.1 Parameterized Constructor" << endl;
    x = a;
    y = b;
  }

  void print() const
  {
    cout << "X=" << x << endl
         << "Y=" << y << endl;
  }
};

int main()
{
  A obj1, obj2(11, 22), obj3(32);

  obj1.print();
  obj2.print();
  obj3.print();
}
