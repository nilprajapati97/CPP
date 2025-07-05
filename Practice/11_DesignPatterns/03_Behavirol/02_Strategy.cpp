/*
✅ 2. Strategy Pattern
====================================================
Use Case: Different sorting algorithms at runtime
*/

#include <iostream>
using namespace std;

class Strategy {
public:
    virtual void execute() = 0;
};

class QuickSort : public Strategy {
public:
    void execute() override { cout << "QuickSort executed\n"; }
};

class MergeSort : public Strategy {
public:
    void execute() override { cout << "MergeSort executed\n"; }
};

class Context {
    Strategy* strategy;
public:
    void setStrategy(Strategy* s) { strategy = s; }
    void run() { strategy->execute(); }
};

int main() {
    Context c;
    QuickSort q;
    MergeSort m;

    c.setStrategy(&q);
    c.run();

    c.setStrategy(&m);
    c.run();
}

/*
        +------------------+
        |   Context        |
        +------------------+
        | -strategy:Strategy|
        | +setStrategy()    |
        | +executeStrategy()|
        +------------------+
                 |
                 ▼
        +------------------+
        |   Strategy       |  ◄───── Interface
        +------------------+
        | +execute()       |
        +------------------+
         ▲           ▲
         |           |
+----------------+ +----------------+
| QuickSort      | | MergeSort      |
+----------------+ +----------------+
| +execute()     | | +execute()     |
+----------------+ +----------------+


*/
