#include <iostream>
#include <stdexcept> // For exception handling

using namespace std;

class MyArray {
private:
    int* arr;
    int size;
    
public:
    // Constructor
    MyArray(int s) : size(s) {
        arr = new int[size]; // Dynamically allocate array
        for (int i = 0; i < size; i++) {
            arr[i] = 0; // Initialize array with zeros
        }
    }

    // Overloading the subscript operator []
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    // Overloading the subscript operator for const objects
    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    // Destructor
    ~MyArray() {
        delete[] arr;
    }
};

int main() {
    
    MyArray myArr(5); // Create an array of size 5

    // Assign values using overloaded []
    myArr[0] = 10;
    myArr[1] = 20;
    myArr[2] = 30;

    // Access values using overloaded []
    cout << "myArr[0] = " << myArr[0] << endl;
    cout << "myArr[1] = " << myArr[1] << endl;
    cout << "myArr[2] = " << myArr[25] << endl;

    // Uncommenting the line below will throw an exception due to out-of-bounds access
    // std::cout << myArr[10] << std::endl;

    return 0;
}
