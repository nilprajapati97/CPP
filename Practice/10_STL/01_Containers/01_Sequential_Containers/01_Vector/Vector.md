STL vector in C++
================================
The vector container in C++ is part of the Standard Template Library (STL). It is a dynamic array that can resize itself automatically when elements are added or removed.

1. Key Features of vector
✅ Dynamic Resizing – Automatically grows when needed.
✅ Contiguous Memory Allocation – Works like an array for fast element access.
✅ Random Access in O(1) Time – Access elements using [] or .at().
✅ Insertion/Deletion Complexity –

O(1) for push_back() (amortized).
O(n) for inserting/deleting in the middle.
✅ Iterators Supported – Supports begin(), end(), rbegin(), rend(), cbegin(), cend().


2. Declaring a vector

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1;              // Empty vector
    vector<int> v2(5);           // Vector of size 5 (default initialized to 0)
    vector<int> v3(5, 10);       // Vector of size 5, initialized to 10
    vector<int> v4 = {1, 2, 3};  // Initializer list

    return 0;
}

3. Basic Operations on vector
(a) Adding and Removing Elements
Function   ->   	Description
----------------------------------------------
push_back(x)        ---> Adds an element at the end
pop_back()          ---> Removes the last element
insert(pos, x)      ---> Inserts x at position pos
erase(pos)          ---> Removes element at pos
clear()             ---> Removes all elements
resize(n, x)        ---> Resizes the vector to n elements (optional fill with x)

