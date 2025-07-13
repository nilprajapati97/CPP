/*
✅ 9. [[nodiscard]] Attribute
Q1. How does [[nodiscard]] prevent bugs?
Q2. Can you apply [[nodiscard]] to structs or types?

🧠 Challenge:
Create a Status struct marked [[nodiscard]]. Return it from functions and verify compiler warning when unused.

✅ Q1. How does [[nodiscard]] prevent bugs?
======================================================================================
[[nodiscard]] tells the compiler to issue a warning/error if a return value is ignored.
This helps prevent logic bugs, especially in cases where the return value must be checked (e.g., error codes, statuses).


[[nodiscard]] int compute() {
    return -1; // should be handled
}

compute(); // ⚠️ Warning: result of 'compute' is discarded

✅ Q2. Can you apply [[nodiscard]] to structs or types?
==========================================================================================
✅ Yes! You can apply [[nodiscard]] to entire user-defined types (e.g., structs, classes).
Any function returning that type will trigger a warning if the result is unused.


*/

#include <iostream>

struct [[nodiscard]] Status {
    bool ok;
    std::string message;
};

// Function that returns Status
Status doWork() {
    return {false, "Something went wrong"};
}

int main() {
    doWork(); // ⚠️ Compiler will warn: 'Status' result is discarded

    // ✅ Correct usage
    Status s = doWork();
    if (!s.ok) {
        std::cerr << "Error: " << s.message << '\n';
    }

    return 0;
}

/*
Output
========
Error: Something went wrong


🧠 Why this helps:
=====================================================================================
For critical functions (like validation, error handling), forgetting to check the result
is a common bug.
[[nodiscard]] forces the developer to acknowledge and handle the result.

*/