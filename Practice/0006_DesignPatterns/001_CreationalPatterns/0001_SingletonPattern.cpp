/*
1️⃣ Singleton Pattern
Ensures a class has only one instance and provides a global access point.

🔹 Example: Logger class (ensures only one log file is used)

*/

#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;  // Single instance
    Singleton() {}  // Private constructor prevents direct instantiation

public:
    static Singleton* getInstance() 
    {
        if (!instance) 
        {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() 
    { 
        cout << "Singleton Instance\n"<<endl;
    }
};

Singleton* Singleton::instance = nullptr; // Initialize static member

int main() {
    Singleton* obj1 = Singleton::getInstance();
    obj1->showMessage();
}

//Use Cases: Logger, Database Connection.
