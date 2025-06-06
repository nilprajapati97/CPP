#include<iostream>
using namespace std;

class A
{
  private: int x;

  public: void get(void)
          {
            cout<<x<<endl;
          }

 };

main()
{
 A a1; //static object is created

 a1.get();

}
