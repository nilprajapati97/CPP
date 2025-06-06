
/*
ARRAY in STL

important member function of array class
- at
- []operato
- front()
- back()
- fill()
- swap()
- size()
- begin()
- end()

*/
#include <iostream>
#include <array>

int main() {
    // Declare and initialize an std::array
    std::array<int, 5> arr = {10, 20, 30, 40, 50};

    // Accessing elements using at()
    std::cout << "Element at index 2: " << arr.at(2) << std::endl;

    // Using front() and back()
    std::cout << "First element (front): " << arr.front() << std::endl;
    std::cout << "Last element (back): " << arr.back() << std::endl;

    // Using fill() to set all elements to a specific value
    arr.fill(100);
    std::cout << "Array after fill(): ";
    for (const auto &elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Using swap() with another array
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    arr.swap(arr2);
    std::cout << "Array after swap(): ";
    for (const auto &elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Using size()
    std::cout << "Size of array: " << arr.size() << std::endl;

    // Using begin() and end() to iterate through the array
    std::cout << "Elements using iterators: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
