#include "MyVector.h"

int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    vec.insert(1, 15);   // Insert 15 at index 1

    for (auto x : vec)
        std::cout << x << " ";  // Output: 10 15 20 30

    vec.erase(2);        // Remove element at index 2

    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
}
