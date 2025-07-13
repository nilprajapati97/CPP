#include <iostream>
using namespace std;


class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    // Overloaded function call operator
    void operator()() {
        count++;
        cout << "Counter called " << count << " times." << endl;
    }
};

int main() {
    Counter counter;

    counter(); // Calls operator() - Increments count
    counter();
    counter();

    return 0;
}
