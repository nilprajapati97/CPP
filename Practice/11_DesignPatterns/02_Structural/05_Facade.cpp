/*
✅ 4. Facade Pattern
🔸Use Case: Provide a simple interface to a complex system
Example: Starting a computer involves CPU, Memory, and Hard Drive — simplify with a single start() method.
*/


#include <iostream>
using namespace std;

class CPU {
public:
    void start() { cout << "CPU started\n"; }
};

class Memory {
public:
    void load() { cout << "Memory loaded\n"; }
};

class HardDrive {
public:
    void read() { cout << "Reading from Hard Drive\n"; }
};

// Facade
class Computer {
    CPU cpu;
    Memory mem;
    HardDrive hdd;
public:
    void start() {
        cpu.start();
        mem.load();
        hdd.read();
    }
};

int main() {
    Computer pc;
    pc.start();  // Client doesn’t need to manage CPU/Mem/HDD separately
}
