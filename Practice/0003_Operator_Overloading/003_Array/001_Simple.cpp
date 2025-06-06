#include <iostream>

class MyArray {
private:
    int arr[5]; // Fixed-size array

public:
    MyArray() { 
        for (int i = 0; i < 5; i++)
            arr[i] = i * 10; // Initialize array
    }

    // Overloading [] operator
    int operator[](int index)
    {
        return arr[index]; 
    }
};

int main() {
    MyArray obj;
    std::cout << obj[2] << std::endl; // Output: 20
    return 0;
}
