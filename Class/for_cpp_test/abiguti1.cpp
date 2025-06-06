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

using namespace A;
using namespace B;
main()
{
  cout<<x<<endl;
  cout<<x<<endl;

}

