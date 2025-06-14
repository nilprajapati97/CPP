#include <iostream>
#include <memory>

using namespace std;

class Tyre {
public:
    void doRepair() {
        cout << "Tyre is being repaired." << endl;
    }
};

class Car {
private:
    shared_ptr<Tyre> wheel1;

public:
    Car() {
        wheel1 = make_shared<Tyre>(); // Correct way to use make_shared
    }

    shared_ptr<Tyre> getwheel1() {
        return wheel1;
    }

private:
    string name;
};

int main() {
    Car car1;
    shared_ptr<Tyre> wheel1 = car1.getwheel1(); // Correct way to assign shared_ptr

    cout << "Shared ownership of the Tyre instance established." << endl;

    return 0;
}
