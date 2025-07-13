#include <iostream>
#include <cstdlib> // For malloc and free

using namespace std;

class MyClass {

private:
    int x;

public:

    void setData(int a)
    {
    	x = a;
    
    }
    // Overloading new operator
    void showData()
    {
	    cout<<"x = "<<x<<endl;
    }

    // Overloading pre increment operator
    MyClass operator ++()  //pre increment
    {
	    MyClass i;

	    i.x = ++x;

	    return i;
    }
    // Overloading post increment operator
    MyClass operator ++(int)  //pre increment
    {
	    MyClass i;

	    i.x = x++;

	    return i;
    }

};

int main() {


    // Pre Using overloaded new
    MyClass i1,i2,i3;

    i1.setData(34);
    i1.showData();

    i2 = ++i1;   //i2 = i1.operator++()
    //i2 = i1++;   // post
    
    i1.showData();
    i2.showData();

    i2.showData();

return 0;
}
