/*
 *      3. Timed Locking (Waiting for a Lock)
 * =============================================
 *      If you want a thread to wait for a lock but give up after a certain time, use try_lock_for().
 *
 * 
 *  */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
mutex mtx;

void timedLockExample() {
    unique_lock<mutex> lock(mtx, defer_lock);

    if (lock.try_lock_for(chrono::milliseconds(500)))
    {
        cout << "Thread " << std::this_thread::get_id() << " acquired the lock.\n";
    } 
    else 
    {
        cout << "Thread " << this_thread::get_id() << " timed out waiting for the lock.\n";
    }
}

int main() {
    std::thread t1(timedLockExample);
    std::thread t2(timedLockExample);

    t1.join();
    t2.join();

    return 0;
}

/*
🔹 Why use std::unique_lock here?
It allows a thread to wait for a lock for a limited time, improving efficiency in time-sensitive applications.


*/
