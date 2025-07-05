
/*
✅ 6. Iterator Pattern
===================================================
Use Case: Traverse a custom container

+---------------------+         +------------------+
| IterableCollection  |◄─────── |   Iterator       |
+---------------------+         +------------------+
| +createIterator()   |         | +hasNext()       |
+---------------------+         | +next()          |
                                +------------------+
                                         ▲
                                         |
                                +------------------+
                                | VectorIterator   |
                                +------------------+


*/

#include <iostream>
#include <vector>
using namespace std;

class Iterator {
    vector<int>& data;
    size_t index = 0;
public:
    Iterator(vector<int>& d) : data(d) {}
    bool hasNext() { return index < data.size(); }
    int next() { return data[index++]; }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Iterator it(nums);
    while (it.hasNext()) cout << it.next() << " ";
}
