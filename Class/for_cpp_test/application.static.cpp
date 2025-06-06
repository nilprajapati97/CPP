#include<iostream>
using namespace std;

class item
{
  private:int item_no;
          string item_name;
	  static int count; 

  public:void set()
  	{
          cout<<"Enter the item_no"<<endl;
          cin>>item_no;

          cout<<"Enter the item_name"<<endl;
          cin>>item_name;
           
          count++;
        }

        void get()
        {
          cout<<item_no<<endl;
          cout<<item_name<<endl;
        } 
  
        void total_count()
        {
          cout<<count<<endl;
        }    
};

int item::count;

main()
{
 item a1,a2,a3;

 a1.set();
 a2.set();
 a3.set();
 
 a1.get();
 a2.get();
 a3.get();

 a1.total_count(); 
}



