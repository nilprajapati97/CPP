✅ 1. Structured Bindings
=======================================================================================
Q1. What are structured bindings?
Q2. How would you extract values from a std::map<K, V> entry using structured bindings?
Q3. Can structured bindings be used with user-defined structs? Provide an example.

🧠 Challenge:
Given a function returning std::tuple<int, std::string, float>, use structured binding to destructure and process the data.

✅ 2. if constexpr
Q1. What is the difference between if constexpr and if?
Q2. How does if constexpr affect template instantiation?

🧠 Challenge:
Implement a templated function that:

Adds two numbers if they are integral

Concatenates if they are strings
Use if constexpr.

✅ 3. std::optional
Q1. How does std::optional improve code safety compared to returning null pointers or sentinel values?
Q2. What are the ways to check if an optional holds a value?

🧠 Challenge:
Implement std::optional<std::string> getUsernameById(int id); that returns empty if user not found.

✅ 4. std::variant
Q1. What is std::variant and how is it different from union?
Q2. What happens if you access the wrong type from a variant?

🧠 Challenge:
Write a std::variant<int, float, std::string> and a visitor that prints type and value using std::visit.

✅ 5. std::string_view
Q1. What are the benefits and risks of std::string_view?
Q2. When would you avoid using string_view?

🧠 Challenge:
Implement a function that splits a string using std::string_view without creating any new strings.

✅ 6. Inline Variables
Q1. What problem does inline solve for global constexpr variables in headers?
Q2. How does it affect ODR (One Definition Rule)?

🧠 Challenge:
Write a Config class with an inline static variable shared across multiple files.

✅ 7. Fold Expressions
Q1. What are fold expressions and how do they simplify variadic templates?
Q2. Can you use fold expressions with custom operators?

🧠 Challenge:
Write a function allOf(...) using fold expression that returns true if all arguments are true.

✅ 8. Filesystem Library
Q1. How do you check if a file exists using C++17 filesystem?
Q2. How do you get a list of all .txt files in a directory?

🧠 Challenge:
Create a folder logs if it doesn't exist. Then scan and delete all .tmp files.

✅ 9. [[nodiscard]] Attribute
Q1. How does [[nodiscard]] prevent bugs?
Q2. Can you apply [[nodiscard]] to structs or types?

🧠 Challenge:
Create a Status struct marked [[nodiscard]]. Return it from functions and verify compiler warning when unused.

✅ 10. __has_include
Q1. What’s the purpose of __has_include?
Q2. How do you use it to make your library portable across compilers?

🧠 Challenge:
Use __has_include(<filesystem>) to fallback to Boost filesystem if standard is unavailable.

