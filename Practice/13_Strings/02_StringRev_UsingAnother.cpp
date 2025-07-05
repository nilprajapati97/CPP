#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseWithStack(const string& input) {
    stack<char> s;
    
    // Push all characters to stack
    for (char ch : input) {
        s.push(ch);
    }

    // Pop from stack to build reversed string
    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string str = "Hello, World!";
    string reversed = reverseWithStack(str);

    cout << "Original: " << str << endl;
    cout << "Reversed: " << reversed << endl;

    return 0;
}
