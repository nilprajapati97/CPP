#include <iostream>
#include <set>
using namespace std;

int main() {
    // 1. Create a multiset and insert elements
    multiset<int> ms = {50, 30, 30, 10, 20, 50};

    cout << "Initial multiset (auto sorted, allows duplicates): ";
    for (int x : ms) cout << x << " ";
    cout << "\n";

    // 2. insert()
    ms.insert(40);
    ms.insert(30);  // duplicate allowed
    cout << "After inserting 40 and 30: ";
    for (int x : ms) cout << x << " ";
    cout << "\n";

    // 3. count()
    cout << "Count of 30: " << ms.count(30) << "\n";

    // 4. find()
    auto it = ms.find(20);
    if (it != ms.end())
        cout << "Found 20\n";
    else
        cout << "20 not found\n";

    // 5. erase() single element (only first occurrence of 30)
    ms.erase(ms.find(30));  // only one '30' is erased
    cout << "After erasing one 30: ";
    for (int x : ms) cout << x << " ";
    cout << "\n";

    // 6. erase() all occurrences of 50
    ms.erase(50);
    cout << "After erasing all 50s: ";
    for (int x : ms) cout << x << " ";
    cout << "\n";

    // 7. equal_range() — get range of duplicates
    auto range = ms.equal_range(30);
    cout << "All 30s: ";
    for (auto it = range.first; it != range.second; ++it)
        cout << *it << " ";
    cout << "\n";

    // 8. lower_bound() and upper_bound()
    cout << "Lower bound of 20: " << *ms.lower_bound(20) << "\n";
    cout << "Upper bound of 30: " << *ms.upper_bound(30) << "\n";

    // 9. size(), empty(), clear()
    cout << "Size: " << ms.size() << "\n";
    cout << (ms.empty() ? "Multiset is empty\n" : "Multiset is not empty\n");

    ms.clear();
    cout << "After clear(), size = " << ms.size() << "\n";

    return 0;
}

/*
Output-:
===========================
Initial multiset (auto sorted, allows duplicates): 10 20 30 30 50 50 
After inserting 40 and 30: 10 20 30 30 30 40 50 50 
Count of 30: 3
Found 20
After erasing one 30: 10 20 30 30 40 50 50 
After erasing all 50s: 10 20 30 30 40 
All 30s: 30 30 
Lower bound of 20: 20
Upper bound of 30: 40
Size: 5
Multiset is not empty
After clear(), size = 0




🧠 Explanation of Each Function
=====================================================
// This section explains the usage of each multiset function demonstrated above.

Function	        Usage	                Description
----------------------------------------------------------------------------------
insert(val)	        ms.insert(40);	        Inserts element while keeping order; duplicates allowed
count(val)	        ms.count(30);	        Returns number of occurrences of val
find(val)	        ms.find(20);	        Returns iterator to the first occurrence
erase(val)	        ms.erase(50);	        Erases all occurrences of val
erase(it)	        ms.erase(ms.find(30));	Erases a single instance via iterator
equal_range(val)	ms.equal_range(30);	    Returns pair of iterators for all instances of val
lower_bound(val)	ms.lower_bound(20);	    Iterator to first element ≥ val
upper_bound(val)	ms.upper_bound(30);	    Iterator to first element > val
size()	            ms.size();	            Returns total number of elements
empty()	            ms.empty();	            Returns true if container is empty
clear()	            ms.clear();	            Removes all elements



*/