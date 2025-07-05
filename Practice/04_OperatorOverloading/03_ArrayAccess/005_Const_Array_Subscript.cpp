#include <iostream>
using namespace std;

class MyArray {
private:
    int arr[5];
    static const int size = 5;

public:
    MyArray()
    { 
        for (int i = 0; i < size; i++) {
            arr[i] = i * 10;
        }
    }

    // Non-const version (allows modification)
    int& operator[](int index)
    {
        if (index < 0 || index >= size) {
            cout << "Index out of range!" << endl;
            return arr[0];
        }
        return arr[index];
    }

    // Const version (read-only)
    const int& operator[](int index) const
    {
        if (index < 0 || index >= size) {
            cout << "Index out of range!" << endl;
            return arr[0];
        }
        return arr[index];
    }
};

int main()
{
    MyArray arr;

    cout << "arr[0] = " << arr[0] << endl;

    arr[0] = 100;
    cout << "arr[0] after modification = " << arr[0] << endl;

    // Now accessing a const array
    const MyArray arrConst;

    cout << "arrConst[0] = " << arrConst[0] << endl;

    // arrConst[0] = 100; // Error: cannot modify a const object

    return 0;
}
