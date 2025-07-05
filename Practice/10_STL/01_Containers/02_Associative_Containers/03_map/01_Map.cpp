/*
✅ What is std::map in C++?
======================================================================
std::map is a sorted associative container that stores key-value pairs.

Keys are unique and automatically kept in sorted order (by default, ascending).

Backed by a balanced binary search tree (Red-Black Tree).

Supports logarithmic time complexity for search, insert, and delete.

*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // 1. Create and initialize map
    map<int, string> myMap;

    // 2. insert() - add key-value pairs
    myMap.insert({1, "One"});
    myMap.insert({3, "Three"});
    myMap[2] = "Two"; // alternative insertion

    // 3. map is sorted by key automatically
    cout << "Initial map (sorted by keys):\n";
    for (auto& pair : myMap)
        cout << pair.first << " => " << pair.second << "\n";

    // 4. find() - search by key
    if (myMap.find(2) != myMap.end())
        cout << "Key 2 found: " << myMap[2] << "\n";

    // 5. at() - access by key with bounds check
    try {
        cout << "Value at key 3: " << myMap.at(3) << "\n";
        // cout << myMap.at(10); // throws out_of_range
    } catch (out_of_range& e) {
        cout << e.what() << "\n";
    }

    // 6. erase() - remove by key
    myMap.erase(1);
    cout << "After erasing key 1:\n";
    for (auto& p : myMap)
        cout << p.first << " => " << p.second << "\n";

    // 7. count() - check if key exists
    cout << "Count of key 2: " << myMap.count(2) << "\n"; // 1 (exists)
    cout << "Count of key 5: " << myMap.count(5) << "\n"; // 0 (doesn’t exist)

    // 8. size(), empty()
    cout << "Size: " << myMap.size() << "\n";
    cout << (myMap.empty() ? "Empty\n" : "Not Empty\n");

    // 9. clear()
    myMap.clear();
    cout << "After clear(), size: " << myMap.size() << "\n";

    return 0;
}
/*
Output-:
==================================
Initial map (sorted by keys):
1 => One
2 => Two
3 => Three
Key 2 found: Two
Value at key 3: Three
After erasing key 1:
2 => Two
3 => Three
Count of key 2: 1
Count of key 5: 0
Size: 2
Not Empty
After clear(), size: 0

*/


/*
🧠 Explanation of Each Major std::map Function
=======================================================================
These functions are commonly used with std::map in C++.

Function	            Description
--------------------------------------------------------------------
insert({k, v})	        Inserts key–value pair. Fails if key already exists.
operator[]	            Inserts key with default value if not exists.
at(k)	                Access value at key with bounds check (throws if missing).
find(k)	                Returns iterator to key k, or end() if not found.
erase(k)	            Removes key k. No-op if not found.
count(k)	            Returns 1 if key exists, 0 otherwise.
size()	                Number of elements.
empty()	                True if map is empty.
clear()	                Removes all elements.


✅ When to Use std::map
=======================================================================
Use std::map when you need:
- Fast lookup by key (O(log n) time complexity)
- Sorted keys (automatically sorted)
- Unique keys (no duplicates allowed)
- Order-sensitive iteration (keys are ordered)

✅ Advanced Tips
========================================================================
These are some advanced features and tips for using std::map effectively:
=======================================================================
Feature	                Example
---------------------------------------------------------------------
Custom comparator	    map<int, string, greater<int>> myMap; // Descending order
Use auto with iterators	auto& [k, v] : myMap; // C++17 structured bindings
Replace value	        myMap[2] = "Updated"; // Updates or inserts 


❗ Difference: map vs unordered_map
=======================================================================
| Feature       | map                | unordered_map      |
|---------------|--------------------|---------------------|
| Backend       | Red-Black Tree     | Hash Table          |
| Order         | Sorted             | No order            |
| Time complexity| O(log n)          | O(1) average        |
| Memory        | Less efficient     | More efficient      |

*/