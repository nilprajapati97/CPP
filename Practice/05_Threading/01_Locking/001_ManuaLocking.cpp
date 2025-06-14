
/*
    ✅ Pros: Simple to use
    ❌ Cons: Risk of forgetting to unlock, leading to deadlocks
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx; // Shared mutex

void threadFunction1() {
    mtx.lock(); // Manually locking
    cout << "Hello from Thread 1" << endl;
    this_thread::sleep_for(chrono::seconds(2)); // Delay for synchronization
    mtx.unlock(); // Manually unlocking
}

void threadFunction2() {
    mtx.lock(); // Manually locking
    cout << "Hello from Thread 2" << endl;
    this_thread::sleep_for(chrono::seconds(2)); // Delay for synchronization
    mtx.unlock(); // Manually unlocking
}

int main() {
    thread t1(threadFunction1);
    thread t2(threadFunction2);
     
    t1.join(); // Wait for thread 1 to finish
    t2.join(); // Wait for thread 2 to finish

    cout << "Both threads have finished execution. Main thread continues." << endl;

    return 0;
}
