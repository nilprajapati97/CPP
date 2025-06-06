#include<iostream>
using namespace std;

int x=10;

main()
{
	int x=20;
	{
		int x=40;    
	//	cout<<x<<endl;
		cout<<::x<<endl<<x<<endl;

	}
}
