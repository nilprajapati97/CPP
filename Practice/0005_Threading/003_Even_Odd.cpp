#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Mutex for synchronization
int counter = 1; // Shared counter
const int MAX_NUM = 20; // Limit

void printEven() {
    while (counter <= MAX_NUM) {
        std::lock_guard<std::mutex> lock(mtx);
        if (counter % 2 == 0) {
            std::cout << "Even: " << counter << std::endl;
            counter++;
        }
    }
}

void printOdd() {
    while (counter <= MAX_NUM) {
        std::lock_guard<std::mutex> lock(mtx);
        if (counter % 2 != 0) {
            std::cout << "Odd: " << counter << std::endl;
            counter++;
        }
    }
}

int main() {
    std::thread t1(printEven);
//    std::thread t2(printOdd);

    t1.join();
//    t2.join();

    return 0;
}

