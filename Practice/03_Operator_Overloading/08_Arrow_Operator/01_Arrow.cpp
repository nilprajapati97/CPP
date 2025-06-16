#include <iostream>
using namespace std;

class MyArrow {
private:
    int number;

public:
    MyArrow(int n) : number(n){}

    int* operator->(){
        return &number;
    }
	
	int& operator*(){
        return number;
    }
};

int main()
{
    MyArrow w(42);
    cout << *w.operator->() << endl; // Prints 42
    // or simply:
    cout << *w << endl; // Incorrect — compiler error
    return 0;
}