#include<iostream>
using namespace std;
main()
{
 int x=10;
 int z=20;
 
 int &y=x;
 int &y=z;//if one varriable use as refrence again u cannot refrence

  cout<<"values are.."<<endl;  
  cout<<"x="<<x<<endl<<"y="<<y<<endl;

  cout<<"addresses are.."<<endl;  
  cout<<"&x="<<&x<<endl<<"&y="<<&y<<endl;
}
