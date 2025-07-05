#include <iostream>
using namespace std;

template <typename T>
class Box {
	T value;
	public:
	Box(T v) : value(v)
       	{
	
	}
	
	T getValue() 
	{
	   return value; 
	}
};

int main() {
	Box<int> intBox(10);
	Box<string> strBox("Hello");

	cout << intBox.getValue() << endl;  // Output: 10
	cout << strBox.getValue() << endl;  // Output: Hello
}

