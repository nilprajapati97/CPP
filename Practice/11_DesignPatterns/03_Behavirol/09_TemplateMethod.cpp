/*
✅ 9. Template Method Pattern
===================================================
Use Case: Game steps are fixed: start → play → end

        +------------------+
        | Game             |
        +------------------+
        | +run()           | ← template method
        | +start() = 0     |
        | +play() = 0      |
        | +end() = 0       |
        +------------------+
                 ▲
                 |
        +------------------+
        | Cricket          |
        +------------------+
        | +start(), etc.   |
        +------------------+


*/
#include <iostream>
using namespace std;

class Game {
public:
    void run() {
        start(); play(); end();
    }
    virtual void start() = 0;
    virtual void play() = 0;
    virtual void end() = 0;
};

class Cricket : public Game {
public:
    void start() override { cout << "Cricket Start\n"; }
    void play() override { cout << "Playing Cricket\n"; }
    void end() override { cout << "Cricket End\n"; }
};

int main() {
    Cricket game;
    game.run();
}
