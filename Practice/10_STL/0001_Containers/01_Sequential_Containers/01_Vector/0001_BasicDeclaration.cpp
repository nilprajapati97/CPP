#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1;              // Empty vector
    vector<int> v2(5);           // Vector of size 5 (default initialized to 0)
    vector<int> v3(5, 10);       // Vector of size 5, initialized to 10
    vector<int> v4 = {1, 2, 3};  // Initializer list

    return 0;
}