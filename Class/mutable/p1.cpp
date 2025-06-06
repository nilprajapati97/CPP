#include<iostream>
using namespace std;

struct A
{
 int x;
 char y;
};

main()
{
  const struct A v={10,'s'};
  v.x=300;
}
