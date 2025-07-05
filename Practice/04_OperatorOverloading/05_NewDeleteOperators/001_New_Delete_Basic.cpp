#include <iostream>
#include <stdlib.h>
using namespace std;

class A
{
private:
    int a;
    char arr[10];

public:
    void set()
    {
        cout << "Enter the value" << endl;
        cin >> a;

        cout << "Enter the name" << endl;
        cin >> arr;
    }

    void display()
    {
        cout << a << endl
             << arr << endl;
    }

    void *operator new(size_t size)
    {
        void *p;

        cout << "In new" << endl;
        p = malloc(size);
        return p;
    }

    void operator delete(void *q)
    {
        cout << "In delete" << endl;
        free(q);
    }
};

int main()
{
    A a1;

    A *s = new A;

    s->set();
    s->display();

    delete s;

    return 0;
}
