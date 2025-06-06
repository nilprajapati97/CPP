#include<iostream>
using namespace std;

class A
{

 public: A(int k)
	{
          cout<<"In base class .."<<endl;
	}

};

class B:public A
{

 public: B():A(100)   // internally like  B(int i):A()
	{
          cout<<"In derived class constructor.."<<endl;
	}
};

main()
{
  B b1();
}
