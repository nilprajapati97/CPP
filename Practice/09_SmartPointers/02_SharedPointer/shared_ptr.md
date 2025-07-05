-: std::shared_ptr
-------------------------------------------------------
std::shared_ptr is a smart pointer in C++ that maintains shared ownership of a dynamically allocated object.
This means multiple std::shared_ptr copies can point to the same object, and it will be freed only when the
last std::shared_ptr is destroyed or reset.


-:Key Points & Benefits of std::shared_ptr in C++
std::shared_ptr is a smart pointer in C++ that manages shared ownership of an object. 
Multiple shared_ptr instances can own the same object, and the object is automatically deleted when the last shared_ptr goes out of scope.

-:Benefit	Description
Prevents Memory Leaks	        -> Automatically deallocates memory when the last reference is gone.
Avoids Dangling Pointers        -> Ensures objects live as long as needed and are destroyed safely.
Simplifies Resource Management	-> No need to manually track and delete objects.
Safe in Multi-Threading	        -> The reference count is atomic, preventing data races.
Breaks Ownership Complexity	    -> Makes passing shared ownership across functions easier.


-:Key Points of std::shared_ptr
====================================
1.Reference Counting
    std::shared_ptr maintains a reference count to track how many shared_ptr instances share ownership of an object.
    When the last shared_ptr is destroyed, the object is automatically deleted.

2.Automatic Memory Management
    Avoids memory leaks by ensuring proper cleanup when no more references exist.

3.Thread-Safe (Atomic Reference Count)
    The reference count is thread-safe, meaning multiple threads can safely use shared_ptr without race conditions.
4.Custom Deleter Support
    Supports custom deleters for special cleanup logic.