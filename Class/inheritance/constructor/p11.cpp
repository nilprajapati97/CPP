#include<iostream>
using namespace std;

class A
{

 public: A()
	{
          cout<<"In base class A constructor.."<<endl;
	}

};

 class B 
{

 public: B()
	{
          cout<<"In base class B constructor.."<<endl;
	}
};

class C:virtual public A,virtual public B
{

 public: C()
	{
          cout<<"In class C constructor.."<<endl;
	}
};
main()
{
  C c1;
}
