#include<iostream>
using namespace std;

class A
{
 	 int x;

	public: void set_data(void)
 		 {
   			x=10;
        	 }
        
                void get_data(void)
                 {
                    cout<<x<<endl;
 		 } 


};   

main()
{
  A a1;

  cout<<"size of object="<<sizeof(a1)<<endl;
  
  a1.set_data(); 
  a1.get_data();

}
