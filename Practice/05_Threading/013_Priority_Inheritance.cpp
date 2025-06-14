/*
3. Use Priority Inheritance for Mutex (RTOS, Embedded Systems)
In embedded RTOS (like FreeRTOS, QNX, or Linux RT), priority inheritance prevents low-priority threads from blocking high-priority ones.

Linux Example (PI Mutex):


✅ Why?

Avoids priority inversion (a low-priority thread blocking a high-priority thread).
RTOS ensures low-priority thread temporarily gets a higher priority until it releases the lock.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <sched.h>
#include <pthread.h>

using namespace std;
pthread_mutex_t pi_mutex;  // Priority Inheritance Mutex

void low_priority_task() {
    pthread_mutex_lock(&pi_mutex);

    cout << "Low-priority thread holding mutex"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    
    pthread_mutex_unlock(&pi_mutex);
}

void high_priority_task() {
    this_thread::sleep_for(chrono::milliseconds(500));
    
    cout << "High-priority thread trying to acquire mutex\n";
    pthread_mutex_lock(&pi_mutex);
    
    cout << "High-priority thread acquired mutex\n";
    pthread_mutex_unlock(&pi_mutex);
}

int main() {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);  // Enable priority inheritance
    pthread_mutex_init(&pi_mutex, &attr);

    std::thread t1(low_priority_task);
    std::thread t2(high_priority_task);

    t1.join();
    t2.join();

    pthread_mutex_destroy(&pi_mutex);
    return 0;
}
