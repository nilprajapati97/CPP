/*
#include<iostream>
using namespace std;

struct A{

	int x;
	char y;


};
int main()
{
	const struct A v={10,'s'};
	return 0;


}
*/
#include<iostream>
using namespace std;

struct A{

	mutable int x;
	char y;


};
int main()
{
	const struct A v={10,'s'};

	v.x = 100;

	v.x = 77;

	cout <<"v.x ="<<v.x<<endl<<"v.y ="<<v.y<<endl;
	return 0;


}
