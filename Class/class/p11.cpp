#include<iostream>
using namespace std;

class A
{
 	 int x;

	public: void set_data(void)
 		 {
   			x=10;
                        get_data();
        	 }
        
       private: void get_data(void)
                 {
                    cout<<x<<endl;
 		 } 


};   

main()
{
  A a1;

  
  a1.set_data(); 

}
