#include<iostream>
using namespace std;

class A
{


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
