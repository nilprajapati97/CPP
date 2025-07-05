#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // 1. Create and initialize multimap
    multimap<int, string> mm;

    // 2. insert()
    mm.insert({1, "Apple"});
    mm.insert({2, "Banana"});
    mm.insert({1, "Avocado"}); // duplicate key
    mm.insert({3, "Cherry"});
    mm.insert({2, "Blueberry"});

    // 3. Traversal - sorted by key, includes duplicates
    cout << "All elements:\n";
    for (const auto& [key, value] : mm) {
        cout << key << " => " << value << '\n';
    }

    // 4. count(key)
    cout << "\nCount of key 1: " << mm.count(1) << "\n";

    // 5. find(key)
    auto it = mm.find(2);
    if (it != mm.end())
        cout << "First value with key 2: " << it->second << "\n";

    // 6. equal_range(key) → range of all values for the key
    cout << "\nAll values with key 2:\n";
    auto range = mm.equal_range(2);
    for (auto i = range.first; i != range.second; ++i) {
        cout << i->first << " => " << i->second << '\n';
    }

    // 7. erase(key) → removes all entries with that key
    mm.erase(1);
    cout << "\nAfter erasing key 1:\n";
    for (const auto& [k, v] : mm)
        cout << k << " => " << v << '\n';

    // 8. erase(iterator) → remove a single element
    auto it2 = mm.find(2);
    if (it2 != mm.end()) mm.erase(it2);
    cout << "\nAfter erasing one instance of key 2:\n";
    for (const auto& [k, v] : mm)
        cout << k << " => " << v << '\n';

    // 9. size(), empty()
    cout << "\nSize of multimap: " << mm.size() << "\n";
    cout << (mm.empty() ? "Multimap is empty\n" : "Multimap is not empty\n");

    // 10. clear()
    mm.clear();
    cout << "After clear(), size: " << mm.size() << "\n";

    return 0;
}

/*
Output:
=========================================
All elements:
1 => Apple
1 => Avocado
2 => Banana
2 => Blueberry
3 => Cherry

Count of key 1: 2
First value with key 2: Banana

All values with key 2:
2 => Banana
2 => Blueberry

After erasing key 1:
2 => Banana
2 => Blueberry
3 => Cherry

After erasing one instance of key 2:
2 => Blueberry
3 => Cherry

Size of multimap: 2
Multimap is not empty
After clear(), size: 0


*/