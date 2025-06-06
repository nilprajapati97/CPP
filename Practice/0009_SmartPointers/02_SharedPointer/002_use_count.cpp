/*
2️⃣ use_count() (Returns reference count)

*/

#include <iostream>
#include <memory>

using namespace std;

int main() {
    
    shared_ptr<int> p1 (new int(10));
    shared_ptr<int> p2; 

    p2=p1; // Shared ownership

    cout << "Reference Count for p1: " << p1.use_count() <<endl; // Output: 1
    cout << "Reference Count for p2: " << p2.use_count() <<endl; // Output: 2

    cout<<"Address of P1->"<<p1.get()<<endl;  // Null
    cout<<"Address of P2->"<<p2.get()<<endl;  // Address also can print
    
    p1.reset();

    cout << "Reference Count for p1: " << p1.use_count() <<endl; // Output: 1
    cout << "Reference Count for p2: " << p2.use_count() <<endl; // Output: 2

    cout<<"Address of P1->"<<p1.get()<<endl;  // Null
    cout<<"Address of P2->"<<p2.get()<<endl;  // Address also can print



}