/*
    std::lock_guard (RAII-Based Locking)
    std::lock_guard<std::mutex> is a simple, RAII-based (Resource Acquisition Is Initialization) 
    locking mechanism that locks a mutex upon creation and automatically unlocks it when the lock_guard object goes out of scope.
*/


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void printMessage(string msg) {
    lock_guard<mutex> lock(mtx); // Locks at start, unlocks automatically at end
    cout << msg << endl;
}

int main() {
    thread t1(printMessage, "Hello from Thread 1");
    thread t2(printMessage, "Hello from Thread 2");

    t1.join();
    t2.join();

    return 0;
}
