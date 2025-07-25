
Benifit of Smart pointer
================================

1. Resource Management
2. Avoiding Memory leaks
3. Avoiding Dangling Pointer
4. Pointer Ownership
5. Simplyfy memory management
6. Avoiding Manual Memory management errors.


=======================================================
1. Automatic Memory Management (RAII)
    Smart pointers (like std::unique_ptr, std::shared_ptr, and std::weak_ptr) automatically release allocated memory when they go out of scope, following the Resource Acquisition Is Initialization (RAII) principle.
2. Prevention of Memory Leaks
    Since smart pointers free memory when they are destroyed, they help prevent memory leaks caused by forgetting to call delete on raw pointers.
3. Exception Safety
    Smart pointers ensure that allocated resources are properly cleaned up even if an exception occurs, preventing resource leaks.
4. Avoidance of Dangling Pointers
    When a smart pointer goes out of scope, it deletes the associated object. This reduces the risk of dangling pointers (accessing memory that has already been freed).
5. Reference Counting (std::shared_ptr)
    std::shared_ptr keeps track of how many pointers share ownership of an object. The object is deleted only when the last shared_ptr that owns it is destroyed.
6. Weak References (std::weak_ptr)
    std::weak_ptr helps avoid circular references in cases where std::shared_ptr objects reference each other, preventing memory from never being freed.
7. Custom Deleters
    Smart pointers allow custom deleters, which is useful for handling objects that require special cleanup (e.g., closing file handles, releasing resources in embedded systems).
8. Better Code Readability & Maintainability
    Using smart pointers makes it clear when ownership is shared or unique, improving code readability and maintainability.