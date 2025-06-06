#include<iostream>
using namespace std;

class item
{
	private: int item_no;
		 string name;
	         static int count;

	public: void set_data(void)
		{
			cout<<"Enter item number"<<endl;
			cin>>item_no;

			cout<<"Enter name"<<endl;
			cin>>name;

			count++;	
		}

		void get_data(void)
		{
			cout<<"item number="<<item_no<<endl;
			cout<<"item name="<<name<<endl;    
		}

	static void total_count(void)  //static member function only acsess the static member
		{
			cout<<"count="<<count<<endl;
		}
};

int item::count;

main()
{
	item i1,i2,i3;

	i1.set_data(); 
	i2.set_data(); 
	i3.set_data(); 

	i1.get_data();
	i2.get_data();
	i3.get_data();

	i1.total_count();
}
