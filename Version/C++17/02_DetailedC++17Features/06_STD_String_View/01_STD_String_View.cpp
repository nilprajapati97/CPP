
/*
✅ 5. std::string_view
================================================================================================
Q1. What are the benefits and risks of std::string_view?
Q2. When would you avoid using string_view?

🧠 Challenge:
Implement a function that splits a string using std::string_view without creating any new strings.



✅ Q1. What are the benefits and risks of std::string_view?
================================================================================================
| Feature               | Benefit                                             |
| --------------------- | --------------------------------------------------- |
| Non-owning            | Avoids heap allocation and copies                   |
| Lightweight           | Just a pointer and size (like `span<char>`)         |
| Interoperable         | Works with literals, `std::string`, `char*`, arrays |
| Efficient for parsing | Ideal for slicing strings (zero-copy `substr()`)    |
| Full STL-style API    | `find`, `starts_with`, iterators, etc.              |
✅ Use Case: Parsers, log processors, network packet decoders

🔸 Example:
====================================
void greet(std::string_view name) {
    std::cout << "Hello, " << name << '\n';
}

std::string user = "Anil";
greet(user);  // No copy of user

🔹 Risks
---------------------------------------------------------------------------------
| Risk                 | Reason                              |
| -------------------- | ----------------------------------- |
| ❌ Dangling view      | Refers to destroyed object (UB)     |
| ❌ Lifetime issues    | View doesn't extend string lifetime |
| ❌ No null terminator | Not compatible with C APIs          |
| ❌ Immutable          | Can't modify underlying data        |
| ❌ Doesn’t own memory | Can't safely store long-term        |


❗Dangerous Example:
----------------------------------------------------------------------------------
std::string_view get() {
    std::string s = "temp";
    return s;  // ❌ UB: s is destroyed
}

std::string_view get() {
    static std::string s = "persistent";
    return s;  // ✅ Safe: s lives for the program's lifetime
}

✅ Q2. When would you avoid using string_view?
================================================================================================
| Situation                               | Why it's a problem                         |
| --------------------------------------- | ------------------------------------------ |
| Returning a view to a local string      | Lifetime ends immediately                  |
| Modifying the data                      | `string_view` is read-only                 |
| Needing null-terminated C strings       | `string_view.data()` isn't null-terminated |
| Persistent storage                      | `string_view` doesn’t manage memory        |
| Using with dynamically changing strings | View may go out of sync                    |


✅ Goal:
------------
    Input: "a,b,c" and delimiter ','
    Output: a list of string_views: ["a", "b", "c"]
    📌 No std::string allocations!



*/
//🔧 Solution (C++17)

#include <iostream>
#include <string_view>
#include <vector>

std::vector<std::string_view> split_sv(std::string_view str, char delim) {
    std::vector<std::string_view> result;

    while (!str.empty()) {
        size_t pos = str.find(delim);

        if (pos == std::string_view::npos) {
            result.push_back(str);
            break;
        }

        result.push_back(str.substr(0, pos));
        str.remove_prefix(pos + 1);  // Advance past delimiter
    }

    return result;
}

int main() {
    std::string line = "C++17,std::string_view,zero-copy";
    auto tokens = split_sv(line, ',');

    for (auto token : tokens)
        std::cout << "[" << token << "]\n";
}

/*
🧪 Output:
===========================
[C++17]
[std::string_view]
[zero-copy]


🔍 Highlights:
============================================================
| Feature                    | Explanation                 |
| -------------------------- | --------------------------- |
| `std::string_view::find()` | Locates delimiter           |
| `substr()`                 | Creates a view (not a copy) |
| `remove_prefix()`          | Moves the view forward      |


🛡 No New Strings Created:
============================================================
    No new, no std::string, no memory allocation.
    Just slicing the original buffer — perfect for high-performance code.
*/
