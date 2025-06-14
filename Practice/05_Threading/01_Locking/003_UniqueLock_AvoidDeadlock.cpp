
/*
    4. Using std::lock to Avoid Deadlocks with Multiple Mutexes
        If multiple threads try to lock the same set of mutexes in different orders, a deadlock may occur. std::lock ensures they are locked in a safe order.
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mtx1, mtx2;

void safeLocking() {
    unique_lock<mutex> lock1(mtx1, defer_lock);
    unique_lock<mutex> lock2(mtx2, defer_lock);

    std::lock(lock1, lock2); // Lock both mutexes safely

    std::cout << "Thread " << std::this_thread::get_id() << " has acquired both locks safely.\n";
}

int main() {
    thread t1(safeLocking);
    thread t2(safeLocking);

    t1.join();
    t2.join();

    return 0;
}
/*
 *
 *
 *
 *🔹 Why use std::unique_lock here?
 *      Using std::lock() ensures both mutexes are locked in a deadlock-free manner.
 *
 * 
 * 
 * 
 * */