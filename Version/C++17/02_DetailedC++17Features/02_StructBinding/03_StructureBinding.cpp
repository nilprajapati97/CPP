/*
✅ Q3. Can structured bindings be used with user-defined structs? Provide an example.
=====================================================================================
🧠 Answer:

Yes, structured bindings work with user-defined structs if:
The struct has public, non-static members.

It behaves like a tuple — i.e., it's an aggregate or has get<> overloads and tuple_size/tuple_element specializations.

*/

#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    Person p = {"Alice", 30};

    auto [n, a] = p; // Structured binding

    std::cout << n << " is " << a << " years old.\n";
}
/*
Output
=================
Alice is 30 years old.

⚠️ This works because Person is a plain aggregate with public members.


*/
