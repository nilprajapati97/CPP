✅ 1. Structured Bindings
============================================================================================================
Q1. What are structured bindings?
----------------------------------------
🧠 Answer:
Structured bindings (introduced in C++17) allow you to unpack a tuple, pair, array, or struct into individual named variables directly.

    auto [var1, var2] = some_tuple_or_pair;

🔍 Use cases:
----------------
01. Unpacking std::pair, std::tuple, or std::map elements
02. Extracting values from arrays or structs
03. Improving readability when working with compound types

🔸 Example with std::pair:
----------------------------------------------------
        std::pair<int, std::string> p = {1, "one"};
        auto [num, word] = p;
        std::cout << num << ", " << word;  // Output: 1, one






Q3. Can structured bindings be used with user-defined structs? Provide an example.
============================================================================================================


