#include<iostream>
#include <memory>
using namespace std;

void my_function()
{
    unique_ptr <int> p1 = make_unique<int>(10); // create a unique pointer to an int initialized to 10
    
    unique_ptr <int> p2;
    
    
    cout<<"*p1->Owner ->>" <<*p1<<endl;
    cout<<"*p2->Owner ->>" <<(p2 ? to_string(*p2) : "nullptr")<<endl;

    //p2=p1;       assignment will not work
    //p2(p1); copy assignment will not work
    
    //transfer ownership
    p2= move(p1);

    if(p1 == nullptr)
        cout<<"p1 is not owner"<<endl;
    else
        cout<<"*p1->"<<*p1<<endl;

    cout<<"*p2->Owner ->>" <<*p2<<endl;

    cout<<"*p1->Owner ->>" <<(p1 ? to_string(*p1) : "nullptr")<<endl;
    cout<<"*p2->Owner ->>" <<(p2 ? to_string(*p2) : "nullptr")<<endl;

}

int main()
{
    my_function();

    cout<<endl;

    return 0;

}