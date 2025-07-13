/*
✅ 1. Structured Bindings
-------------------------------------
🔹 Purpose:
Unpack tuple-like objects (e.g., std::tuple, std::pair, structs) into individual variables.

*/

#include <iostream>
#include <tuple>
using namespace std;

int main() {
    tuple<int, string> t = {1, "Anil"};
    auto [id, name] = t;
    cout << id << ", " << name << endl;
}
//Explanation: Unpack tuple or struct directly into variables.