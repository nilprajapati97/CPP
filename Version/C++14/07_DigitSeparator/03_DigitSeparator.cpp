 /*
🔹 2. Digit Separators: ' (single quote)
===========================================================
🔧 Syntax:
-------------
    int readable = 1'000'000;   // easier to read than 1000000
 
🧠 Why?
================================================================
Makes large numbers more human-readable, like how commas are used:
    int readable = 1'000'000;   // 1 million
    int hex_value = 0xAB'CD'EF'12; // hex value with digit separators (hex memory layout)

Compiler ignores ' when parsing number.
 
 */

 #include <iostream>
 using namespace std;

int main() {
    int salary = 1'000'000;
    int hex    = 0xDE'AD'BE'EF;  // clearer hex layout

    cout << "Salary: " << salary << endl;
    cout << "Hex value: " << hex << endl;

    return 0;
}
// Output:
// Salary: 1000000
// Hex value: deadbeef