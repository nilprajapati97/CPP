#include<iostream>
using namespace std;
main()
{
  int x=10;
  int &y=x;
  
  cout<<"values are.."<<endl;  
  cout<<"x="<<x<<endl<<"y="<<y<<endl;

  cout<<"addresses are.."<<endl;  
  cout<<"&x="<<&x<<endl<<"&y="<<&y<<endl;
 
}
