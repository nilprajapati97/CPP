#include <iostream>
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx; // For thread-safety

    // Private constructor
    Singleton()
    {
        std::cout << "Singleton instance created!" << std::endl;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance()
    {
        if (instance == nullptr)
        { 
            std::lock_guard<std::mutex> lock(mtx);
            
            if (instance == nullptr)
            {  // Double-checked locking
                instance = new Singleton();
            }
        
        }
        return instance;
    }

    void doSomething() {
        std::cout << "Singleton method called!" << std::endl;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->doSomething();

    Singleton* s2 = Singleton::getInstance();
    s2->doSomething();

    std::cout << "s1 address: " << s1 << std::endl;
    std::cout << "s2 address: " << s2 << std::endl;

    return 0;
}
