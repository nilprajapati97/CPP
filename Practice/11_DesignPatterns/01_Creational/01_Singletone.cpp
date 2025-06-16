#include <iostream>
#include <mutex>
using namespace std;
class Singleton {
private:
    static Singleton* instance;
    static mutex mtx; // For thread-safety

    // Private constructor
    Singleton()
    {
        cout << "Singleton instance created!" << endl;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance()
    {
        if (instance == nullptr)
        { 
            lock_guard<mutex> lock(mtx);
            
            if (instance == nullptr)
            {  // Double-checked locking
                instance = new Singleton();
            }
        
        }
        return instance;
    }

    void doSomething() {
        cout << "Singleton method called!" << std::endl;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->doSomething();

    Singleton* s2 = Singleton::getInstance();
    s2->doSomething();

    cout << "s1 address: " << s1 << endl;
    cout << "s2 address: " << s2 << endl;

    return 0;
}
