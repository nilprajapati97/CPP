Why Use weak_ptr in C++?
std::weak_ptr is used in C++ to prevent circular references (memory leaks) when working with std::shared_ptr.

Problem: Circular Reference in shared_ptr
If two objects hold std::shared_ptr to each other, they never get deleted, causing a memory leak.