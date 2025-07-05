// assignment operator overloading

#include <iostream>
using namespace std;

class A
{
private:
  int x;

public:
  void setdata()
  {
    x = 100;
  }

  void display()
  {
    cout << x << endl;
  }
};

int main()
{
  A a1, a2(a1);
  a1.setdata();
  a2 = a1;
  a2.display();

  return 0;
}
