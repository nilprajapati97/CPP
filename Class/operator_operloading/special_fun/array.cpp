// [] array subscript operator

#include<iostream>
using namespace std;

class A
{
	private: int a[5];

	public: void setdata()
		{
			for(int i=0;i<5;i++)
				a[i]=i+10;
		}

		int operator[](int k)
		{
			return a[k];
		}
};

main()
{
	A a1;

	a1.setdata();

	int  y=a1[2];  // a1.operator[](2);

	cout<<y<<endl;
}
