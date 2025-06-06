#include<iostream>
using namespace std;

class A
{
  public:A()
	{
          cout<<"In base class A contrustor.."<<endl;
        }

        ~A()
	{
          cout<<"In base class A destructor.."<<endl;
	}
};

class B:public A
{
  public:B()
	{
          cout<<"In derived class B constructor.."<<endl;
	}

  
	~B()
	{
          cout<<"In derived class B destructor.."<<endl;
	}
};
main()
{
 B b1;
}

