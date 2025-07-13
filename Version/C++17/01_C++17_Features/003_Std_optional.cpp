/*
✅ 3. std::optional
========================================
🔹 Purpose:
Represent optional (nullable) values safely without special sentinel values.

*/

#include <iostream>
#include <optional>
using namespace std;

optional<int> find(bool ok) {
    if (ok) return 42;
    return nullopt;
}

int main() {
    auto val = find(true);
    if (val) cout << *val << endl;

    auto val2 = find(false);
    if (val2) cout << *val2 << endl;
}
/*
Output:
===========
42
*/
/*
Explanation: std::optional<int> can hold an int or be empty (nullopt). 
Use *val to access the value safely.


🔹 std::nullopt — What is it?
std::nullopt is a special constant that represents an empty (no value) state for an std::optional.

It's similar to nullptr for pointers — it means:
👉 “no valid value is present”.


std::nullopt is used to initialize or reset an std::optional to an empty state.
It allows you to create an optional that doesn't hold any value, indicating that the value is absent
or not applicable.
For example:
std::optional<int> opt = std::nullopt; // opt is empty, no value
std::optional<int> opt2; // Also empty, default constructor is equivalent to std::nullopt
std::optional<int> opt3 = 42; // opt3 holds the value 42
opt3 = std::nullopt; // Now opt3 is empty again, no value
   

✅ Real-world use: Replace raw pointers or invalid return values
================================================================
*/
