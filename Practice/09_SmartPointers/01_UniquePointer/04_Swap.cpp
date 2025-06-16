/*
4.  swap() – Swap Two Unique Pointers
    Swaps ownership between two std::unique_ptr objects.
*/

#include <iostream>
#include <memory>

using namespace std;

class Car
{

private:
    string name;

public:
    Car(const string &name) : name(name)
    {
    }

    void show()
    {
        cout << "Car: " << name << endl;
    }
};

int main()
{

    unique_ptr<Car> carA = make_unique<Car>("BMW");
    unique_ptr<Car> carB = make_unique<Car>("Audi");

    carA->show();
    carB->show();

    carA.swap(carB); // Swap ownership

    carA->show();
    carB->show();

    return 0;
}
