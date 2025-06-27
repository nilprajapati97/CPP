#include <iostream>
#include <variant>
using namespace std;

int main() {
    variant<int, string> data;
    data = "Hello"s;
    cout << get<string>(data) << endl;
}
//Explanation: Type-safe union that holds one of multiple types.