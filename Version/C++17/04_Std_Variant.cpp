/*
✅ 4. std::variant
=========================
🔹 Purpose:
Type-safe union — holds exactly one of several types.
*/

#include <iostream>
#include <variant>
using namespace std;

int main() {
    variant<int, string> data;
    data = "Hello"s;
    cout << get<string>(data) << endl;
}
// Output:
// Hello
//Explanation: Type-safe union that holds one of multiple types.

//✅ Safer than union, no type confusion. 