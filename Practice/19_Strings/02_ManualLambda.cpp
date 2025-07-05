#include <iostream>
#include <string>
using namespace std;
int main() {
    string str = "I love India";

    // Lambda to reverse string manually using two-pointer technique
    auto reverseStr = [](string &s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    };

    cout << "Before reversing string: " << str << endl;
    reverseStr(str);
    cout << "After reversing string: " << str << endl;

    return 0;
}
