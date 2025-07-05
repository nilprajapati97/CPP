#include <iostream>
using namespace std;

class MyArray {
	private:
		int arr[5]; // Fixed-size array
		static const int size = 5;

	public:
		MyArray()
		{ 
			for (int i = 0; i < size; i++) {
				arr[i] = i * 10; // Initialize array
			}
		}

		// Overloading [] operator with range checks
		int& operator[](int index)
		{
			if (index < 0 || index >= size) {
				cout << "Index out of range!" << endl;
				// Handle gracefully — here we return first element
				return arr[0];
			}
			return arr[index];
		}

		// Const version (so we can use with const MyArray)
		const int& operator[](int index) const
		{
			if (index < 0 || index >= size) {
				cout << "Index out of range!" << endl;
				return arr[0];
			}
			return arr[index];
		}

		int getSize() const { return size; }
};

int main()
{
	MyArray obj;

	// Accessing within range
	cout << "arr[0] = " << obj[0] << endl;
	cout << "arr[4] = " << obj[4] << endl;

	// Accessing corner cases (out of range)
	cout << "arr[-1] = " << obj[-1] << endl;
	cout << "arr[5] = " << obj[5] << endl;

	return 0;
}


/*

🔹 Why int& instead of int 🔹:
When you do:
    int& operator[](int index);
        …the compiler returns a reference to the actual array element instead of a copy.

This lets you:

✅ Read or modify the element directly.
✅ Use the subscript on the left side of an assignment.

For example:
    
MyArray arr;

// This would be invalid if we returned by value:
arr[0] = 100;

// But with a reference, we modify the actual array:
   arr[0] = 100;
🔹 If We Did This 🔹:
--------------------------------------------------------
    int operator[](int index) // return by value
    {
        return arr[index];
    }

-: We would return a copy, not a reference.

-: This means we couldn’t modify the array directly.

-: An expression like arr[0] = 100; would produce a compiler error:

“lvalue required”

🔹 Summary 🔹:
--------------------------------------
✅ Returning by reference lets us modify the array in place.
✅ Returning by value would produce a new copy — not desirable if you want to enable assignment.

*/
