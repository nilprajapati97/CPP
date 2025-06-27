#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto ptr = make_unique<int>(10);
    auto l = [p = move(ptr)] { cout << *p << endl; };
    l();
}
