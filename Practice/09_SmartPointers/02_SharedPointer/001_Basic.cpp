/*
1️⃣ std::make_shared (Preferred way to create shared_ptr)
*/
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sp = std::make_shared<int>(100);
    std::cout << "Value: " << *sp << std::endl;  // Output: 100
}