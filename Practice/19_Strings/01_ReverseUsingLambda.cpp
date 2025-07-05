#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string str = "I love C++";

    // Lambda to reverse the string in place
    auto reverseStr = [](string &s) {
        reverse(s.begin(), s.end());
    };


    cout << "Before string: " << str << endl;
    reverseStr(str);
    cout << "Reversed string: " << str << endl;

    return 0;
}
