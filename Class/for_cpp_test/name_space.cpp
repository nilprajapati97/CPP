#include<iostream>
using namespace std;

namespace A
{
  int x=10;
  int y=20;
}

namespace B
{
  int x=20;
  int y=30;
}

using  A::x;
using  B::y;
main()
{
  cout<<x<<endl;
  cout<<y<<endl;
}

