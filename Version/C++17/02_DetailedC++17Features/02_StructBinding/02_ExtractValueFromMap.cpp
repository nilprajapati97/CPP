/*
Q2. How would you extract values from a std::map<K, V> entry using structured bindings?
============================================================================================================

🧠 Answer:
            std::map<K, V>::iterator yields a std::pair<const K, V>. You can directly unpack key and value
            like this:


*/

#include <map>
#include <iostream>

int main() {
    std::map<int, std::string> m = {{1, "India"}, {50, "Vector"}, {99,"Prajapati"},{4,"Anil"}};

    for (const auto& [key, value] : m) {
        std::cout << key << ": " << value << '\n';
    }
}

/*
Output
===========
1: India
4: Anil
50: Vector
99: Prajapati

🔸 Benefit:
No more verbose .first and .second!
Structured bindings improve clarity and intent in such loops.


*/