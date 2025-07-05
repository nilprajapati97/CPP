#include <iostream>
using namespace std;

void display(int, int = 20); // here provide int=20 is a default argument

main()
{
  display(10);
}

void display(int a, int b)
{
  cout << a << endl
       << b << endl;
}
