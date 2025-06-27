#include <memory>
#include <iostream>
using namespace std;

int main() {
    auto ptr = make_unique<int>(100);
    cout << *ptr << endl;
}
