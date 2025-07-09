#include<iostream>
#include <cstring>
using namespace std;

class A{

	char *str;
	public:
	A(const char *p)
	{
	cout<< "01 Default Constructor" <<endl;
	 str = new char[sizeof(strlen(p))]+1;
         strcpy(str,p);
	}

	A(A& obj)
	{
	cout<< "02 Copy Constructor" <<endl;
	
	 str = new char[sizeof(strlen(obj.str))]+1;
         strcpy(str,obj.str);
	}
	void modiy()
	{
	str[0] = 'S';
	}
	void display()
	{
	cout<<"string-:"<<str<<endl;
	
	}
};

int main()
{
 A a1("vetcor");
 A a2 = a1;

 a1.modiy();
 a1.display();
 a2.display();
 return 0;

}
