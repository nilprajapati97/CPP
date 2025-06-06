#include<iostream>
using namespace std;

class A
{
  private:mutable int x;
 	  mutable int y;

  public:void set_data() const
          {
	    x=10;
            y=20;	
	  } 
};

main()
{
 A a1;
 
 a1.set_data();

}
