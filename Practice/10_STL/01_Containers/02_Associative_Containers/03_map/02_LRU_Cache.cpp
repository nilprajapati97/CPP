/*

✅ 2. LRU Cache (Least Recently Used) – with map + list
=============================================================
🔧 Use Case:
Design a cache system that holds a fixed number of items and removes the least recently used item when the cache exceeds the limit.

🔧 Why Use map?
Store keys for fast lookup

Use std::list to maintain access order

std::map + std::list gives O(log n) insert/remove and O(1) reordering.

✅ Simplified LRU Cache Example (Key-Value)
*/

#include <iostream>
#include <map>
#include <list>
using namespace std;

class LRUCache {
    int capacity;
    list<int> usageOrder;  // MRU at front, LRU at back
    map<int, pair<int, list<int>::iterator>> cache; // key -> (value, usage iterator)

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // Move key to front (most recently used)
        usageOrder.erase(cache[key].second);
        usageOrder.push_front(key);
        cache[key].second = usageOrder.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            usageOrder.erase(cache[key].second);
        } else if (cache.size() == capacity) {
            // Remove least recently used
            int lru = usageOrder.back();
            usageOrder.pop_back();
            cache.erase(lru);
        }

        // Insert as most recently used
        usageOrder.push_front(key);
        cache[key] = {value, usageOrder.begin()};
    }

    void printCache() {
        cout << "Cache content (MRU -> LRU): ";
        for (int key : usageOrder)
            cout << key << " ";
        cout << "\n";
    }
};

int main() {
    LRUCache cache(3);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    cache.printCache(); // 3 2 1

    cache.get(2);
    cache.printCache(); // 2 3 1

    cache.put(4, 400);
    cache.printCache(); // 4 2 3 (1 is evicted)

    return 0;
}
/*
🧠 Output:
===========
Cache content (MRU -> LRU): 3 2 1
Cache content (MRU -> LRU): 2 3 1
Cache content (MRU -> LRU): 4 2 3
*/