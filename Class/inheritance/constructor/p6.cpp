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

 public: B(int i,int j)
	{
          cout<<"In derived class constructor.."<<endl;
	}
};

main()
{
  B b1(10,20);
}
