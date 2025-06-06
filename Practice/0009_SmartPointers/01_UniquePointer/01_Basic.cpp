#include<iostream>
#include <memory>
using namespace std;

void my_function()
{
    unique_ptr <int> p1 (new int(10));
    unique_ptr <int> p2;
    cout<<"*p1->>"<<*p1<<endl;
}

int main()
{
    my_function();

    cout<<endl;

    return 0;

}