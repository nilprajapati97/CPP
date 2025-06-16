/*

7. operator bool() – Check If unique_ptr Holds an Object
   Returns true if std::unique_ptr holds an object, otherwise false.

*/

#include <iostream>
#include <memory>
using namespace std;

int main() {
    
    unique_ptr<int> ptr;
    
    if (!ptr) {
        cout << "Pointer is empty\n";
    }

    ptr = make_unique<int>(42);

    if (ptr) {
       cout << "Pointer holds value: " << *ptr << "\n";
    }

    return 0;
}
