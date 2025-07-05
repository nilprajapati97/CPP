/*
✅ 8. State Pattern
===================================================
Use Case: Media player changes behavior: Playing, Paused, Stopped

+-------------+         +-------------+
|   Context   | ------> |   State     | ◄── Interface
+-------------+         +-------------+
| -state      |         | +press()    |
| +setState() |         +-------------+
| +press()    |
+-------------+
        ▲                  ▲
        |                  |
+-------------+     +-------------+
| Playing     |     | Paused      |
+-------------+     +-------------+
| +press()    |     | +press()    |
+-------------+     +-------------+


*/

#include <iostream>
using namespace std;

class State {
public:
    virtual void press() = 0;
};

class Playing : public State {
public:
    void press() override { cout << "Pausing music\n"; }
};

class Paused : public State {
public:
    void press() override { cout << "Resuming music\n"; }
};

class Player {
    State* state;
public:
    Player(State* s) : state(s) {}
    void setState(State* s) { state = s; }
    void pressButton() { state->press(); }
};

int main() {
    Playing play;
    Paused pause;
    Player player(&play);
    player.pressButton();  // Pausing
    player.setState(&pause);
    player.pressButton();  // Resuming
}
