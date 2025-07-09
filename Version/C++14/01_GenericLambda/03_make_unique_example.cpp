/*
03. std::make_unique
Introduced to complement std::unique_ptr

*/


#include <iostream>
#include <memory>  // For std::unique_ptr and std::make_unique
using namespace std;
int main() {
    // ✅ Create a unique pointer to an int with value 10
    unique_ptr<int> ptr = make_unique<int>(10);

    // ✅ Access and print the value
    cout << "Value = " << *ptr << endl;

    // ✅ No need to delete manually — memory is automatically released when ptr goes out of scope

    return 0;
}
// Output:
// Value = 10
// Memory is automatically released when ptr goes out of scope
// No manual delete needed
