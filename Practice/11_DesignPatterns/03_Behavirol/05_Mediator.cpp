
/*
✅ 5. Mediator Pattern
===================================================
Use Case: Chat room managing communication

        +-----------------+
        |   Mediator      | ◄──── Interface
        +-----------------+
        | +send()         |
        +-----------------+
              ▲
              |
        +---------------------+
        |  ChatMediator       |
        +---------------------+
        | +send()             |
        +---------------------+
         ▲              ▲
         |              |
+----------------+  +----------------+
| Colleague A    |  | Colleague B    |
+----------------+  +----------------+
| -mediator      |  | -mediator      |
| +send()        |  | +send()        |
| +receive()     |  | +receive()     |
+----------------+  +----------------+


*/

#include <iostream>
#include <string>
using namespace std;

class Mediator;

class Colleague {
protected:
    Mediator* mediator;
public:
    void setMediator(Mediator* m) { mediator = m; }
    virtual void send(string msg) = 0;
    virtual void receive(string msg) = 0;
};

class Mediator {
public:
    virtual void send(string msg, Colleague* sender) = 0;
};

class ConcreteColleague : public Colleague {
public:
    void send(string msg) override;
    void receive(string msg) override {
        cout << "Received: " << msg << endl;
    }
};

class ChatMediator : public Mediator {
    Colleague* c1;
    Colleague* c2;
public:
    void registerUsers(Colleague* a, Colleague* b) {
        c1 = a; c2 = b;
        a->setMediator(this); b->setMediator(this);
    }
    void send(string msg, Colleague* sender) override {
        if (sender == c1) c2->receive(msg);
        else c1->receive(msg);
    }
};

void ConcreteColleague::send(string msg) {
    mediator->send(msg, this);
}

int main() {
    ChatMediator mediator;
    ConcreteColleague user1, user2;
    mediator.registerUsers(&user1, &user2);
    user1.send("Hello from User1");
}
