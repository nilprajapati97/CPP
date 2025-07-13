#include <iostream>
using namespace std;

class A {
	private:
		int x;

	public:
		A()
		{
			cout << "In Default Constructor function" << endl;
			x = 10;
		}

		void display()
		{
			cout << "In display function-: x = " << x << endl;
		}    

		A operator-()
		{
			cout << "In unary minus operator:" << endl;

			A temp;

			temp.x = -temp.x;

			return temp;
		}
};

int main()
{
	A a1 , a2;
	a1.display();

	-a1;  // This expression performs the unary minus and RETURNs a new object — it doesn't modify a1 itself

	a1.display();
	a2= -a1;
	a2.display();

	return 0;
}
