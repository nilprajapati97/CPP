#include<iostream>
using namespace std;

class A
{
  public:int x;
};

class B:virtual public A
{
  public:int y;
};

class C:virtual public A
{
  public:int z;
};


class D:public B,public C
{
  public:int k;
};


main()
{
 D d1;
 
 d1.k=100;
 d1.z=200;
 d1.y=300;
 d1.x=500;
}
