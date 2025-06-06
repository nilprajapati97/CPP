#include<iostream>
using namespace std;

class A
{
 public: A()
	{
          cout<<"In base class constructor.."<<endl;
	}
};

class B:public A
{

};

main()
{
  B b1;
}
