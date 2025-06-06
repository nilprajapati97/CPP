#include<iostream>
using namespace std;

class Time
{
	private:int hr;
		int min;

	public:Time()
	       {

	       }

	       Time(int k)
	       {
		       hr=(k/60);
		       min=(k%60);		
	       } 

	       void display()
	       {
		       cout<<"hr="<<hr<<endl<<"min="<<min<<endl;
	       }
};

main()
{
	int y=90;
	Time t1;

	t1=y;

	t1.display();
}  

