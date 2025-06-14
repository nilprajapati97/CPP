📍 Pointer vs Reference in C++

Feature	                        Pointer	                                    Reference
Definition	        Variable that stores address of another variable        Alias for another variable.
Null	            Can be nullptr.	                                        Must always refer to a valid object.
Reassignment	    Can point to different objects anytime.                 Cannot be changed after initialization.
Syntax	            Use * for declaration and dereferencing.                Use & for declaration, no special syntax for use.
Memory Address      Has its own memory (stores an address).                 Shares memory with the object it refers to.
Example             int* p = &x;                                            int& r = x;
Null                Safety	Unsafe, needs checks (if (p != nullptr))        Safer, no null references (in standard C++).








int a = 10;

// Pointer
int* p = &a;
*p = 20;   // modifies a

// Reference
int& r = a;
r = 30;    // modifies a


In short:

Use pointer if you need nullability or reassignability.

Use reference when you want guaranteed binding and safer syntax.

Reference to Array in C++
You can create a reference to an entire array, not just to a single element.

✏ Syntax:

type (&refName)[size] = arrayName;

type → type of elements (e.g., int, char).

size → size of the array.

refName → your reference variable name.

arrayName → existing array.


int arr[5] = {1, 2, 3, 4, 5};

// Reference to the entire array
int (&ref)[5] = arr;

ref[0] = 100; // modifies arr[0]



🔥 Why use reference to an array?
Avoid copying arrays into functions.

Preserve array size information.

Safer and faster than passing pointers sometimes.





void printArray(int (&arr)[5]) {
    for (int i = 0; i < 5; ++i)
        std::cout << arr[i] << " ";
}

int main() {
    int myArr[5] = {10, 20, 30, 40, 50};
    printArray(myArr); // passed by reference
}

Advantages-:
=====================
Increase the execution speed.
Memory consuption
Reduce the complexity
