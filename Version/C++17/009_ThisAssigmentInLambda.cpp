#include <iostream>
using namespace std;
class A {
    int x = 5;
public:
    void show() {
        auto l = [=, this]() { cout << x << endl; };
        l();
    }
};
int main() {
    A obj;
    obj.show();
}
