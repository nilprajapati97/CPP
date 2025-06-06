#include<iostream>
using namespace std;

class A
{
 	private: int x;

	public: void set_data(void)
 	 {
   		x=10;
                cout<<x<<endl;
 	 }
};

main()
{
  A a1;
  
  a1.set_data(); 

}
