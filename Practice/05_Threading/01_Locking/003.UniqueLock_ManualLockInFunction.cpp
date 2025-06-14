#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
mutex mtx;

void criticalSection() {
    unique_lock<mutex> lock(mtx);
    cout << "Thread " << this_thread::get_id() << " has acquired the lock.\n";

    this_thread::sleep_for(chrono::seconds(1)); // Simulating work

    lock.unlock(); // Manually unlocking before doing more work

    this_thread::sleep_for(chrono::seconds(1)); // Simulating work outside the critical section

    cout << "Thread " << this_thread::get_id() << " has finished work.\n";
}

int main() {
    thread t1(criticalSection);
    thread t2(criticalSection);

    t1.join();
    t2.join();

    return 0;
}
