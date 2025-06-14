#include <iostream>
using namespace std;
/*

   Constructore which does not accept any params called defalt constructure
   If Explicitily constructore not cALLED THAN dEAFAULT CONSTRUCTOR USED.


*/

class A
{
	int x;
	int y;

	public:
	A() : x(10), y(20)
	{
		cout << "01.Constructor" << endl;
	}

	A(int a) : x(a), y(100)
	{
		cout << "02.0 Parameterized Constructor" << endl;
	}

	A(int a, int b) : x(a), y(b)
	{
		cout << "02.1 Parameterized Constructor" << endl;
	}

	A(A &obj) : x(obj.x), y(obj.y)
	{
		cout << "03. Copy Constructor" << endl;
	}

	void print() const
	{
		cout << "X=" << x << endl
			<< "Y=" << y << endl;
	}
};

int main()
{
	A obj1, obj2(11, 22), obj3 = obj1;

	obj1.print();
	obj2.print();
	obj3.print();
}

/*
🔁 1. Avoid Infinite Recursion
If you pass the object by value, like this:


A(A obj); // ❌ Wrong!
	Then, when you call the copy constructor, it tries to copy the object — but that means calling the copy constructor again, which again tries to copy... and this creates infinite recursion, leading to stack overflow.

🏃 2. Efficiency
	Passing by reference avoids creating a temporary copy of the object. Passing by value means copying, which is expensive, especially for large objects. Reference avoids this.

✅ Use const A &obj
Most correct version is:
A(const A &obj) : x(obj.x), y(obj.y)
{
    cout << "03. Copy Constructor" << endl;
}
const ensures the object passed won’t be modified inside the constructor.

This allows copying of const objects, temporary objects, etc.

🔍 Summary:
Version				Valid?			Reason
===============================================
A(A obj)			❌				Causes infinite recursion
A(A &obj)			✅				Valid but limits to non-const objects
A(const A &obj)		✅✅				Best Practice — handles all objects safely



*/
