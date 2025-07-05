#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx; // Mutex to protect shared resource

void printMessage(const string& message, int count) {
    for (int i = 0; i < count; ++i)
    {
        lock_guard<mutex> lock(mtx);  // Lock mutex (automatically unlocked when out of scope)
        cout << message << " " << i + 1 <<endl;
    }
}

int main() {
    
    thread t1(printMessage, "Thread 1 running", 5);
    thread t2(printMessage, "Thread 2 running", 5);

    t1.join();
    t2.join();

    cout << "Both threads have finished execution."<<endl;
    return 0;
}
