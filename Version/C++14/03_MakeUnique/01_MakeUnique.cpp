/*
03. std::make_unique
Introduced to complement std::unique_ptr

*/


#include <iostream>
#include <memory>  // For std::unique_ptr and std::make_unique

int main() {
    // ✅ Create a unique pointer to an int with value 10
    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    // ✅ Access and print the value
    std::cout << "Value = " << *ptr << std::endl;

    // ✅ No need to delete manually — memory is automatically released when ptr goes out of scope

    return 0;
}
