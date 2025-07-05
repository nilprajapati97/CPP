#include <iostream>
using namespace std;

// A class demonstrating:
// - Assignment Operator
// - Index Operator
// - Arrow Operator
// - Func­tion Call Operator
class Container {
private:
    int arr[5];
    int size;
    int number;

public:
    // Constructor
    Container(int n = 0) : size(5), number(n) {
        for(int i = 0; i < size; i++) arr[i] = 0;
    }

    // 1️⃣ Assignment Operator (Member)
    Container& operator=(const Container& other) {
        if(this == &other) return *this;
        number = other.number;
        size = other.size;
        for(int i = 0; i < size; i++) arr[i] = other.arr[i];
        return *this;
    }

    // 2️⃣ Index Operator (Member)
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of range!" << endl;
            return arr[0]; // fallback
        }
        return arr[index];
    }

    // 3️⃣ Arrow Operator (Member)
    Container* operator->(){
        return this;
    }

    void print(){
        cout << "Number = " << number << endl;
    }

    // 4️⃣ Func­tion Call Operator (Member)
    void operator()(int n) {
        number = n;
        cout << "Number updated to " << number << endl;
    }
};

int main()
{
    Container c1(100);
    Container c2(200);

    // Assignment
    c1 = c2;

    // Index Operator
    c1[0] = 10;
    c1[1] = 20;

    cout << "c1[0] = " << c1[0] << endl;
    cout << "c1[1] = " << c1[1] << endl;

    // Arrow Operator
    c1->print();

    // Func­tion Call Operator
    c1(500);
    c1->print();

    return 0;
}

