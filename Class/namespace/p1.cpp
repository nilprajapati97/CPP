#include<iostream>
using namespace std;

namespace A
{
  int x=10;
}

namespace B
{
  int x=20;
}

main()
{
  cout<<A::x<<endl;
}
