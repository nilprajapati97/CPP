/*
 2. Use Timeout-Based Locking (try_lock_for)
Use std::timed_mutex to wait for a limited time instead of blocking indefinitely.

✅ Why?

If a thread fails to acquire the lock within 100ms, it moves on instead of blocking forever.


*/
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
timed_mutex tmtx;

void task(int id) {
    if (tmtx.try_lock_for(chrono::milliseconds(100)))
    {  // Try locking for 100ms
        cout << "Thread " << id << " acquired the lock"<<endl;
        this_thread::sleep_for(chrono::milliseconds(200));
        tmtx.unlock();
    } else {
        std::cout << "Thread " << id << " could not acquire lock (timeout)\n";
    }
}

int main() {
    thread t1(task, 1);
    thread t2(task, 2);

    t1.join();
    t2.join();

    return 0;
}
