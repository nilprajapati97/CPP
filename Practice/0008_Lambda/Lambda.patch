What is Lambda?
=====================================

-> A lambda expression is a function without name and non-reusable cod.
-> Lambda one time usable function.
-> It is inline function.
-> It can access values and reference of parent function variables.

why to use lambda over function in c++

Feature                    Lambda                     Regular Function
--------------------------------------------------------------------

------------------------------------------------------------------------
Conciseness                ✅ Shorter & inline      🚫 Requires separate function
Capturing Local Variables  ✅ Possible              🚫 Not possible
Used for Callback          ✅ Idea                  🚫 Requires function pointers
STL Integration            ✅ Easy to use           🚫 Requires extra function
Code Readability           ✅ More readable         🚫 More boilerplate

Syntax
===============

[Capture List] (params)  -> return-type

{
   // code
}

1. No capture

========================================
[]()  ->  auto {}

2. Capture by copy

==================================================
[=]()  ->  auto { ... }       not recomended
[a,b,c]()  ->  auto { ... }       recomended

3. Capture by reference
==================================================
[&]()  ->  auto { ... }          not recomended

[&a,&b,&c]()  ->  auto { ... }       recomended

4.  Capture by copy and reference
==================================================
[&,a]()  ->   auto { ... }      - a is captured by copy everything else is capture by reference
[=,&a]()  ->  auto { ... }      - a is captured by reference, everything elese is capture by reference

Why lambda ?
---------------------------------------------

It seems overkill to be writing a whole class(functor) or function when you have use it only once.
