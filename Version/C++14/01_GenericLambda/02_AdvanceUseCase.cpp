//🧰 Advanced Use Case — Sorting with Generic Lambda

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> vec = {5, 2, 8, 1};

    sort(vec.begin(), vec.end(), [](auto a, auto b) {
        return a < b;
    });

    for (auto x : vec) cout << x << " ";
    cout << endl;
}
// Output: 1 2 5 8
// Explanation: Generic lambda sorts any type of vector (int, float, etc.) without needing
// template or function overloading. It uses auto to accept any type of elements in the vector
// and sorts them in ascending order. This is a powerful feature of C++14 that simplifies
// generic programming by allowing you to write concise and flexible code that works with different types.

