/*
✅ 4. Chain of Responsibility
============
Use Case: Logging framework


+-----------+     +-----------+     +-----------+
| Handler   | --> | Handler   | --> | Handler   |
+-----------+     +-----------+     +-----------+
    ^                                   ^
    |                                   |
+-------------+              +-------------------+
| InfoHandler |              | ErrorHandler      |
+-------------+              +-------------------+


*/

#include <iostream>
using namespace std;

class Handler {
protected:
    Handler* next;
public:
    void setNext(Handler* n) { next = n; }
    virtual void handle(int level) {
        if (next) next->handle(level);
    }
};

class InfoHandler : public Handler {
public:
    void handle(int level) override {
        if (level == 1) cout << "Info: Handled\n";
        else Handler::handle(level);
    }
};

class ErrorHandler : public Handler {
public:
    void handle(int level) override {
        if (level == 3) cout << "Error: Handled\n";
        else Handler::handle(level);
    }
};

int main() {
    InfoHandler info;
    ErrorHandler error;

    info.setNext(&error);
    info.handle(3);  // Forwarded to error
}
