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
Warning: ignoring return value of 'int calculate()', declared with attribute nodiscard [-Wunused-result]    
*/