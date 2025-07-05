std::lock_guard (RAII-Based Locking)
std::lock_guard<std::mutex> is a simple, RAII-based (Resource Acquisition Is Initialization) locking mechanism that locks a mutex upon creation and automatically unlocks it when the lock_guard object goes out of scope.

Pros of std::lock_guard
=================================================================================================
-> 1.Automatic Unlocking (Safety)
    No need to manually unlock the mutex, reducing the risk of deadlocks due to missing unlock() calls.
-> 2. Exception Safety
    If an exception occurs within the critical section, std::lock_guard ensures that the mutex is still released.
-> 3. Simplicity
    No explicit lock() and unlock() calls, making code cleaner and easier to maintain.
-> 4.Better Readability
    Developers can immediately understand that a mutex is being used within the scope.

Cons of std::lock_guard
==========================================================================================================
-> 1. Scope Boundaries
    Since it unlocks when it goes out of scope, you cannot explicitly control the lock duration beyond that.
-> 2. No Try-Lock Support
    std::lock_guard does not support try_lock(), which can be needed in scenarios where locking is optional.
-> 3. No Timeout Handling
    Unlike std::unique_lock, std::lock_guard does not support timed locking.


When and Where to Use std::lock_guard
=========================================================================================================
✅ Best Use Cases
-> 1. Short Critical Sections
    When a mutex needs to be locked for a short duration within a function.
-> 2. Exception-Prone Code
    When an exception might be thrown, ensuring the mutex is always released.
-> 3. Simple Synchronization Needs
    When manual lock() and unlock() calls are not necessary.
-> 4. Multi-Threaded Logging
    Ensures safe access to log files without risk of missing unlocks.

❌ When NOT to Use std::lock_guard
=========================================================================================================
-> 1. Need for Conditional Unlocking
    Use std::unique_lock if you need to unlock and relock the mutex manually.
-> 2. Need for Try-Lock or Timed-Lock
    Use std::unique_lock if you need try_lock() or try_lock_for().
-> 3. Long Critical Sections
    Holding a lock for a long time may reduce parallel performance.

Example Use Case in a Practical Scenario
1. Protecting Shared Resources
When multiple threads access a shared resource, std::lock_guard ensures safe access:


#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int sharedCounter = 0;

void incrementCounter() {
    std::lock_guard<std::mutex> lock(mtx); // Locks and unlocks automatically
    sharedCounter++;
    std::cout << "Counter: " << sharedCounter << std::endl;
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    return 0;
}


2. Logging in a Multi-Threaded Environment
When multiple threads write logs, std::lock_guard ensures synchronized output.

#include <iostream>
#include <thread>
#include <mutex>

std::mutex logMutex;

void logMessage(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    std::cout << "Log: " << message << std::endl;
}

int main() {
    std::thread t1(logMessage, "Thread 1 executed.");
    std::thread t2(logMessage, "Thread 2 executed.");

    t1.join();
    t2.join();

    return 0;
}



Conclusion
✅ Use std::lock_guard for simple, safe, and automatic mutex management in short critical sections.
❌ Avoid std::lock_guard if you need manual unlocking, try-locking, or timeouts.