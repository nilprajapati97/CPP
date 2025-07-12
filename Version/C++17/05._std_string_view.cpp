/*
✅ 5. std::string_view
🔹 Purpose:
Non-owning reference to a string — fast and memory-efficient.

🔹 Characteristics:
- Lightweight: No memory allocation, just a pointer and size.
- Safe: Cannot outlive the original string.
- Efficient: Ideal for passing strings without copying.

*/

#include <iostream>
#include <string_view>
using namespace std;

void greet(string_view name) {
    cout << "Hello " << name << "\n";
}

int main() {
    string s = "BMW";
    greet(s);         // No copy
    greet("Audi");    // Works with literals
}
/*
output:
Hello BMW
Hello Audi
*/
