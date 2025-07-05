/*
1️⃣ std::make_shared (Preferred way to create shared_ptr)
*/
#include <iostream>
#include <memory>
using namespace std;
int main() {
    shared_ptr<int> sp = make_shared<int>(100);
    cout << "Value: " << *sp <<endl;  // Output: 100
}