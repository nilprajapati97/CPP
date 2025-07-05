/*
1. Avoid Deadlocks: Use try_lock() Instead of lock()
Instead of blocking forever, try_lock() attempts to lock a mutex but fails if another thread holds it.

✅ Why?

try_lock() prevents deadlocks by avoiding infinite waiting.
Threads retry after some delay to avoid busy looping.



*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;

void task(int id) {
    while (true) {
        if (mtx.try_lock()) {  // Try to acquire lock
            std::cout << "Thread " << id << " acquired the lock\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate work
            mtx.unlock();
            break;  // Exit loop after successful execution
        } else {
            std::cout << "Thread " << id << " waiting for lock...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Avoid busy waiting
        }
    }
}

int main() {
    std::thread t1(task, 1);
    std::thread t2(task, 2);

    t1.join();
    t2.join();

    return 0;
}
