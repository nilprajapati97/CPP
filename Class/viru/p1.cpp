#include<iostream>
using namespace std;
class A;
class B
{
	public:void getdata(A);
          
};
class A
{

	private:int income1;
		int income2;
	public:void setdata()
	       {
		       cout<<"enter income1 nd income 2.."<<endl;
		       cin>>income1;
		       cin>>income2;
	       }
	       void display()
	       {
		       cout<<income1<<endl;
		       cout<<income2<<endl;
	       }

	       friend void B::getdata(A);
};
void B::getdata(A a)
{

  cout<<"class b function...."<<endl; 
	cout<<a.income1<<endl<<a.income2<<endl;
}
main()
{
	A a1;
	B b1;

	a1.setdata();
	a1.display();
	b1.getdata(a1);
//        b1.modify(A);
}
