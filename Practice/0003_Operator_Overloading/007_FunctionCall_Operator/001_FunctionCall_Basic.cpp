#include <iostream>
using namespace std;

class A
{
private:
    int x;
    char y;

    void setdata()
    {
        cout << "Enter Integer and charachter value" << endl;
        cin >> x >> y;
    }

    void display()
    {
        cout <<"x = "<< x << endl
             << "y ="<<y << endl;
    }

public:
    void operator()(int a)
    {
        setdata();
        cout << "Before change" << endl;
        display();

        x = x + a;
        cout << "After change" << endl;
        display();

        cout << "Recived value is" << endl;
        cout << y << endl;
    }
};

int main()
{
    A a1;

    a1(5);

    return 0;
}