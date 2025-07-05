/*
✅ 3. Command Pattern
===================================================
Use Case: Undo/Redo in a text editor

        +----------------+
        |  Invoker       |
        +----------------+
        | -command       |
        | +setCommand()  |
        | +execute()     |
        +----------------+
                 |
                 ▼
        +----------------+
        |  Command       | ◄───── Interface
        +----------------+
        | +execute()     |
        +----------------+
         ▲
         |
+---------------------+     +---------------------+
| LightOnCommand      |     | LightOffCommand     |
+---------------------+     +---------------------+
| +execute()          |     | +execute()          |
+---------------------+     +---------------------+
         ▲
         |
     +--------+
     | Light  |
     +--------+
     | +on()  |
     | +off() |
     +--------+


*/
#include <iostream>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
};

class Light {
public:
    void turnOn() { cout << "Light ON\n"; }
};

class LightOnCommand : public Command {
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() override { light->turnOn(); }
};

class Remote {
    Command* command;
public:
    void setCommand(Command* c) { command = c; }
    void pressButton() { command->execute(); }
};

int main() {
    Light light;
    LightOnCommand cmd(&light);
    Remote remote;
    remote.setCommand(&cmd);
    remote.pressButton();
}
