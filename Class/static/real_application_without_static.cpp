#include<iostream>
using namespace std;

class item
{
 private:int item_no;
  	 string name;
 
//static int count;
	int count;

 public: void set_data()
      {
       cout<<"Enter the item number"<<endl;
       cin>>item_no;
       cout<<"enter the name"<<endl;
       cin>>name;
       count++;
      }

  void get_data()
     {
       cout<<"item no="<<item_no<<endl;
       cout<<"item name="<<name<<endl;
       
     }

  void init()  //not requred if count take static if not take static take this function
    {
      count=0;
    }

  void total_count()
    {
     cout<<"count="<<count<<endl;
    }
};

//int item::count;


main()
{
  item i1,i2,i3;

  i1.init(); // not requred if count take static if not take static take this function
  i2.init(); //not requred if count take static if not take static take this function
  i3.init(); //not requred if count take static if not take static take this function
   
  i1.set_data();
  i2.set_data();
  i3.set_data();
 
  i1.get_data();
  i2.get_data();
  i3.get_data();

  i1.total_count();
}
