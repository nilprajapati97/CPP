/*
✅ 3. std::optional<T> — Optional Value Holder
================================================================================================
🧠 Purpose:
    01. std::optional<T> represents an object that may contain a value or be empty
        (disengaged). It's a type-safe alternative to:
    
    A. Returning nullptr
    B.Returning sentinel values (e.g., -1, 0, or empty string)
    C. Using flags or out-parameters


✅ Q1. How does std::optional improve code safety compared to null pointers or sentinel values?
=================================================================================================

🔍 Problem with nullptr or sentinel values:
    Null pointer can be dereferenced → UB (Undefined Behavior)
    Sentinel values (like -1 or "") are ambiguous, error-prone, and may conflict with valid data
    No compile-time enforcement — user can forget to check before using

✅ std::optional<T> improves safety by:
==================================================================================================
| Feature                      | Benefit                                             |
| ---------------------------- | --------------------------------------------------- |
| **Type-safe**                | Encapsulates "value or nothing" in the type system  |
| **Compile-time enforcement** | Forces the caller to explicitly check for existence |
| **Cleaner APIs**             | No need for dummy/sentinel returns                  |
| **Avoids raw pointers**      | Prevents nullptr dereferencing                      |

*/

//✅ C++17 Code Using std::optional
#include <iostream>
#include <optional>  // for std::optional

// Function to return even number if input is even
std::optional<int> find_even(int x) {
    if (x % 2 == 0)
        return x;              // return the number as std::optional<int>
    else
        return std::nullopt;   // return empty optional if x is odd
}

int main() {
    int input = 5;

    // Call function and store result in optional
    std::optional<int> result = find_even(input);

    // Check if the result contains a value
    if (result)
        std::cout << "Found: " << *result << "\n";  // access value using *
    else
        std::cout << "No even number found\n";      // std::nullopt branch
}

//✅ Safer than returning -1 or nullptr which could be misused or misunderstood

/*
Output:
-------------------
No even number found


✅ Q2. What are the ways to check if an optional holds a value?
==================================================================================================

🔸 1. Using if (opt)
--------------------------------------------------------------------------------------------------
        std::optional<int> opt = 42;
        if (opt) {
            std::cout << "Value = " << *opt << "\n";
        }


🔸 2. Using .has_value()
--------------------------------------------------------------------------------------------------

        if (opt.has_value()) {
            std::cout << "Value = " << opt.value() << "\n";
        }
🛑 .value() throws std::bad_optional_access if no value is present.

🔸 3. Using .value_or(default)
--------------------------------------------------------------------------------------------------

        int val = opt.value_or(0);  // returns 42 if present, else 0

🔸 4. Pattern with structured bindings (C++23)
--------------------------------------------------------------------------------------------------

        if (auto val = get_optional(); val) {
            std::cout << *val << '\n';
        }


🔸 5. Using std::optional's comparison operators
--------------------------------------------------------------------------------------------------

        if (opt == std::nullopt) {
            std::cout << "No value\n";
        } else {
            std::cout << "Value = " << *opt << "\n";
        }


🔍 Summary Table
===================================================================================================
| Method                | Description                                      |
| --------------------- | -------------------------------------------------|
| if (opt)              | Checks if optional has a value                   |
| .has_value()          | Explicit check for value presence                |
| .value()              | Accesses value, throws if empty                  |
| .value_or(default)    | Returns value or default if empty                |
| Structured bindings   | C++23 feature for cleaner access                 |
===================================================================================================

✅ Best Practices
---------------------------------------------------------------------------------------------------
->  Prefer if (opt) or .has_value() over .value()

->  Use .value_or() for fallback/defaults

->  Avoid using raw pointers or sentinel values in modern C++ APIs

*/