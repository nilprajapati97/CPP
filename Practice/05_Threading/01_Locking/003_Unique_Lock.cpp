#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void printMessage(string msg) {
    unique_lock<mutex> lock(mtx); // More flexible than lock_guard
    cout << msg << endl;
    lock.unlock(); // Manual unlocking if needed
}

int main() {
    thread t1(printMessage, "Hello from Thread 1");
    thread t2(printMessage, "Hello from Thread 2");

    t1.join();
    t2.join();

    return 0;
}
