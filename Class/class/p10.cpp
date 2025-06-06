#include<iostream>
using namespace std;

class A
{
 	 int x;

	public: void set_data(void)
 		 {
   			x=10;
        	 }
        
        private: void get_data(void)
                 {
                    cout<<x<<endl;
 		 } 


};   

main()
{
  A a1,a2;

  cout<<"size of object="<<sizeof(a1)<<endl;
  
  a1.set_data(); 
  a1.get_data();
  a2.get_data(); 

}
