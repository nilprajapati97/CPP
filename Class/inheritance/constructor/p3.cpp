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

 public: B()
	{
          cout<<"In derived class constructor.."<<endl;
	}
};

main()
{
  B b1;
}
