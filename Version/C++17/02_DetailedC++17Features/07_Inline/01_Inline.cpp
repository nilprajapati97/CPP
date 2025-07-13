/*
✅ 6. Inline Variables
Q1. What problem does inline solve for global constexpr variables in headers?
Q2. How does it affect ODR (One Definition Rule)?

🧠 Challenge:
Write a Config class with an inline static variable shared across multiple files.

✅ Q1. What problem does inline solve for global constexpr variables in headers?
================================================================================================

When you define a global constexpr variable in a header file, it leads to multiple definitions
across translation units, violating the One Definition Rule (ODR). This causes linker errors.

🧠 Problem Before C++17:
-----------------------------------------------------
When you define a constexpr variable in a header file:

        constexpr int max_connections = 100;

This leads to multiple definitions in different translation units, causing linker errors.

✅ It compiles per translation unit, but multiple definitions at link time violate the ODR (One Definition Rule) — leading to linker errors.

✅ Solution: inline variables
================================================================================================


    // config.h
    inline constexpr int max_connections = 100;

This allows the variable to be defined in multiple translation units without violating ODR.
✔ Now, it's allowed to have one identical definition per translation unit. The linker merges them.

🔸 Summary:
================================================================================================
- inline variables allow global constexpr variables to be defined in headers without violating ODR.
- They can be defined in multiple translation units without linker errors.

| Feature                     | Before C++17              | With C++17 inline                |
| --------------------------- | --------------------------| ---------------------------------|
| Header-only constants       | ❌ Causes multiple defs   | ✅ Allowed with `inline`         |
| Static constexpr class vars | ❌ Needs out-of-class def | ✅ Can be in-class with `inline` |
| Eliminates ODR violations   | ❌                        | ✅                               |


✅ Q2. How does inline affect ODR (One Definition Rule)?
=================================================================================================
    ODR: A variable/function can be defined in only one translation unit, unless marked inline.

With inline:
    - You can define the variable in multiple translation units (like header files)
    - The compiler ensures it's merged into one definition
    - Safe, deduplicated, and linkable across files
=================================================================================================

✅ Step-by-step Solution
========================

📁 Config.h

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    static inline std::string app_name = "ChatApp";  // shared across files
};

#endif


// 📁 main.cpp

#include <iostream>
#include "Config.h"

int main() {
    std::cout << "Application Name: " << Config::app_name << std::endl;
    return 0;
}

*/

//📁 main.cpp
#include "Config.h"
#include "Module.h"
#include <iostream>

int main() {
    std::cout << "App: " << Config::app_name << "\n";
    Config::app_name = "CLI-Messenger";
    print_config();
    return 0;
}

/*
Compile and run:
-------------------
    g++ -std=c++17 01_Inline.cpp Module.cpp -o config_demo

    ./config_demo

Output:
--------------------
App: ChatApp
Updated Config: CLI-Messenger



🔍 Summary of Usage:
-----------------------------------------------------------------------------
| Keyword                      | Purpose                                    |
| ---------------------------- | ------------------------------------------ |
| `inline`                     | Enables **multiple definitions** (headers) |
| `static`                     | Makes it **class-scoped**                  |
| `constexpr` or `std::string` | Can be both literal or dynamic             |



*/
