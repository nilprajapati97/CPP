#include<iostream>
using namespace std;

namespace a
{
  int x=10;
  int y=100;
}

namespace b
{
  int x=20;
  int y=200;
}

using b::y;
using a::x;

main()
{
  cout<<x<<endl<<y<<endl;

}
