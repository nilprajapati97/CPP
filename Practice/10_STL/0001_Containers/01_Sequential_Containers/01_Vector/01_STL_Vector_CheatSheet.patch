### **C++ STL `vector` Cheat Sheet**

A `vector` in C++ is a **dynamic array** that can resize itself automatically when elements are added or removed.

---

### **1. Include the Header**
```cpp
#include <vector>
using namespace std;
```

---

### **2. Declaration & Initialization**
```cpp
vector<int> v1;                // Empty vector
vector<int> v2(5, 10);         // Vector of size 5, all elements initialized to 10
vector<int> v3 = {1, 2, 3, 4}; // Vector with initial values
vector<int> v4(v3);            // Copy constructor
```

---

### **3. Basic Operations**
```cpp
v1.push_back(10);  // Add element at the end
v1.pop_back();     // Remove last element
v1.size();         // Returns size of vector
v1.capacity();     // Returns current capacity (storage)
v1.empty();        // Checks if vector is empty
v1.clear();        // Removes all elements
```

---

### **4. Accessing Elements**
```cpp
cout << v1[0];       // Direct access (no bounds checking)
cout << v1.at(0);    // Safe access with bounds checking
cout << v1.front();  // First element
cout << v1.back();   // Last element
```

---

### **5. Iterating Over a Vector**
```cpp
// Using index-based loop
for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
}

// Using range-based loop
for (int num : v1) {
    cout << num << " ";
}

// Using iterators
for (auto it = v1.begin(); it != v1.end(); it++) {
    cout << *it << " ";
}
```

---

### **6. Modifying a Vector**
```cpp
v1.insert(v1.begin() + 1, 20);    // Insert 20 at 2nd position
v1.erase(v1.begin());             // Remove first element
v1.erase(v1.begin(), v1.begin() + 2); // Remove first two elements
v1.resize(10, 5);                 // Resize to 10 elements, new elements initialized to 5
```

---

### **7. Sorting & Reversing**
```cpp
#include <algorithm>

sort(v1.begin(), v1.end());       // Sort in ascending order
sort(v1.begin(), v1.end(), greater<int>()); // Sort in descending order
reverse(v1.begin(), v1.end());    // Reverse the vector
```

---

### **8. Searching & Finding**
```cpp
#include <algorithm>

auto it = find(v1.begin(), v1.end(), 5); // Find element 5
if (it != v1.end()) cout << "Found at: " << (it - v1.begin());
```

---

### **9. Swapping & Copying**
```cpp
vector<int> v2 = {10, 20, 30};
v1.swap(v2);  // Swap contents of two vectors
v2 = v1;      // Copy one vector to another
```

---

### **10. 2D Vector (Matrix)**
```cpp
vector<vector<int>> matrix(3, vector<int>(4, 0)); // 3x4 matrix filled with 0

matrix[1][2] = 5; // Set row 1, column 2 to 5
```

---

### **Common Use Cases**
✔ **Dynamic arrays**  
✔ **Efficient insertions/removals at the end**  
✔ **Sorting, searching, and modifying collections**  
✔ **2D arrays (matrices)**  

