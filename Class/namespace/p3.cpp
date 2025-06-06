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
main()
{
  cout<<a::x<<endl<<b::y<<endl;

}
