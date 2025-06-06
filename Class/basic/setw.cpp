#include<iostream>
#include<iomanip>
using namespace std;
main()
{
  int x;
   
  cout<<"enter the value of x.."<<endl;
  cin>>x;
  cout<<setw(5)<<x<<endl;

  cout<<setw(5)<<setfill('$')<<x<<endl;

}
