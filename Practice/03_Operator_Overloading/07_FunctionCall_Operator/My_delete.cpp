
/*
Functors can be used in STL algorithms like std::sort()


Functors are objects that behave like functions by overloading operator().
They can maintain state, unlike normal functions or function pointers.
Functors are widely used in STL algorithms like std::sort(), std::for_each(), etc.
They provide flexibility for passing logic as a callable object.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DescendingOrder {
public:
    bool operator()(int a, int b) {
        return a > b;  // Sort in descending order
    }
};

int main() {
    vector<int> nums = {5, 2, 9, 1, 7};

    sort(nums.begin(), nums.end(), DescendingOrder()); // Using functor

    for (int num : nums) {
        cout << num << " ";
    }
    cout<<endl;
    return 0;
}
