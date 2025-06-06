#include<iostream>
using namespace std;

struct A
{
mutable int x;
 char y;
};

main()
{
  const struct A v={10,'s'};
  v.x=300;

  v.x=200;

  cout<<v.x<<endl<<v.y<<endl; 
}
