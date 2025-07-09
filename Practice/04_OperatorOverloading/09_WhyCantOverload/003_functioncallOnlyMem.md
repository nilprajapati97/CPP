In C++, overloading the function call operator () allows objects to be called like functions. However, unlike other operators, the function call operator must be overloaded as a member function—it cannot be a friend function.

❗ Why You Can't Use friend to Overload operator():
==========================================================
The function call operator requires access to the internal state of the object (this pointer).

friend functions are non-member, so they do not have a this pointer, which is essential for simulating a "call" on the object.

Therefore, operator() must be a non-static member function.