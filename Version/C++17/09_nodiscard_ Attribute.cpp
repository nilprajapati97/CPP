/*
✅ 9. [[nodiscard]] Attribute
========================================
🔹 Purpose:
Warn if return value is ignored.

*/

[[nodiscard]] int calculate() {
    return 99;
}

int main() {
    calculate(); // Warning: result not used
}
/*
Output:

Warning: ignoring return value of 'int calculate()', declared with attribute 
nodiscard [-Wunused-result]
// Explanation: [[nodiscard]] ensures you don't accidentally ignore important return values.
// Use it for functions where the return value is crucial, like error codes or results.
// Example: Use it for functions that return error codes or results that must be checked.
