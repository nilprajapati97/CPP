#include <iostream>
using namespace std;

class MyArrow {
private:
    int *number;

public:
    // Constructor
    MyArrow(int n) 
    {
        number = new int(n);
    }

    // Default constructor (creates a NULL)
    MyArrow()
    {
        number = NULL;
    }

    // Arrow operator with corner case check
    MyArrow* operator->()
    {
        if (number == NULL) 
        {
            cout << "Error: Attempt to dereference a NULL pointer!" << endl;
            // Handle gracefully by allocating or fallback
            number = new int(0);
        }
        return this;
    }

    // Method to print number
    void print()
    {
        if (number == NULL) 
        {
            cout << "Error: number is NULL!" << endl;
        }
        else 
        {
            cout << "Number = " << *number << endl;
        }
    }

    // Method to set number
    void set(int n)
    {
        if (number == NULL) 
        {
            cout << "Error: number is NULL!" << endl;
            number = new int(0);
        }
        *number = n;
    }

    // Destructor
    ~MyArrow()
    {
        delete number;
    }
};

int main()
{
    MyArrow w(42);
    w->print();

    MyArrow wEmpty;
    wEmpty->print();

    wEmpty->set(100);
    wEmpty->print();

    return 0;
}

/*
output -:
-------------------

Number = 42
Error: Attempt to dereference a NULL pointer!
Number = 0
Number = 100

*/
