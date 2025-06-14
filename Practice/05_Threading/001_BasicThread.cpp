#include <iostream>
#include <thread>

// Function to be executed by a thread
void printMessage(const std::string& message, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << message << " " << i + 1 << std::endl;
    }
}

int main() {
    // Creating threads
    std::thread t1(printMessage, "Thread 1 running", 5);
    std::thread t2(printMessage, "Thread 2 running", 5);

    // Waiting for threads to complete
    t1.join();
    t2.join();

    std::cout << "Both threads have finished execution.\n";
    return 0;
}

