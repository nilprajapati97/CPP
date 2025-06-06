#include<iostream>
using namespace std;
main()
{
  string a="vector";
  string b="india";
  string c;

  cout<<"before swap.."<<endl;
  cout<<a<<endl<<b<<endl;

  a.swap(b);

  cout<<"after swap.."<<endl;
  cout<<a<<endl<<b<<endl;

}
