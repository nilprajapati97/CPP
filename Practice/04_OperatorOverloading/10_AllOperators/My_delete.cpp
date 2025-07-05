#include <iostream>
using namespace std;
// Assignment operator
class My{

	private : int x,y;
	public:
		  My()
		  {
			  x= 44;
			  y= 55;
		  }
		  My(int a, int b):x(a),y(b)
	{

	}
		  void operator =(My &obj)
		  {
			  cout<<"Assignment operator.."<<endl;
			  x = obj.x;
			  y = obj.y;
		  }	 
		  void print()
		  {
			  cout<< "x: = "<<x<<endl;
			  cout<< "y: = "<<y<<endl;
		  }
		  /*
		     void set(int n)
		     {
		     if(num == NULL)
		     {
		     cout<< "Error : number is NULL...!"<<endl;
		     num = new int (0);
		     }
		   *num = n;
		   }
		   */
};

int main()
{
	My obj1(10,20),obj2;

	obj2.print();
	obj2= obj1;
	// obj2.operator = (obj1)
	obj2.print();

	return 0;
}

