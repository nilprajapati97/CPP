#include <iostream>
using namespace std;
int main()
{
    int a=4 ,b = 5;

    //[](int a,int b) -> void {cout<<a<<" "<<b<<endl;}(a,b);

    //Step [1]
    //[](int a,int b) -> void { cout<<a<<" "<<b<<endl;a=7; }(a,b);
    //[](int a,int b) -> void {a=7; cout<<a<<" "<<b<<endl; }(a,b); // Call by value

    //[](int &a,int &b) -> void { cout<<a<<" "<<b<<endl;a=7; }(a,b); // Call by reference

    //Step [2]
    // error: no match for call to ‘(main()::<lambda()>) (int&, int&)
    //[=]() -> void { cout<<a<<" "<<b<<endl;a=7; }();  // Capture by value , non mutable lambda (Not change)

    //[&]() -> void { a=7; cout<<a<<" "<<b<<endl; }();  // Capture by value , non mutable lambda (Not change)


    //Step [2]
    // error: no match for call to ‘(main()::<lambda()>) (int&, int&)
    [=]() -> auto { cout<<a<<" "<<b<<endl; }();  // Capture by value , non mutable lambda (Not change)

    //[&]() -> void { a=7; cout<<a<<" "<<b<<endl; }();  // Capture by value , non mutable lambda (Not change)

     //[]

    cout<<endl<<"a"<<"->"<<a<<endl;

    return 0;



}