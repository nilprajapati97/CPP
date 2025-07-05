#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // ✅ Insert elements
    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(5);  // Duplicate, will be ignored

    cout << "Contents of set: ";
    for (int val : s) {
        cout << val << " ";  // Output: 1 3 5 (sorted, no duplicates)
    }
    cout << "\n";

    // ✅ Check existence
    if (s.find(3) != s.end()) {
        cout << "3 is found in set.\n";
    }

    // ❌ Will not find 10
    if (s.find(10) == s.end()) {
        cout << "10 is not found in set.\n";
    }

    // ✅ Erase element by value
    s.erase(3);  // Removes 3
    cout << "After erasing 3: ";
    for (int val : s) cout << val << " ";  // Output: 1 5
    cout << "\n";

    // ✅ Size and empty check
    cout << "Size: " << s.size() << "\n";   // Output: 2
    cout << "Is empty: " << s.empty() << "\n";  // false

    // ✅ Lower and upper bound
    s.insert(7);
    s.insert(9);
    cout << "Lower bound of 5: " << *s.lower_bound(5) << "\n";  // 5
    cout << "Upper bound of 5: " << *s.upper_bound(5) << "\n";  // 7

    // ✅ Clear all elements
    s.clear();
    cout << "After clear, size: " << s.size() << "\n";  // 0

    return 0;
}
