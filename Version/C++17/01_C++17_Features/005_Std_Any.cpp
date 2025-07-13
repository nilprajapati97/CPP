#include <iostream>
#include <any>
using namespace std;

int main() {
    any a = 5;
    a = string("Test");
    cout << any_cast<string>(a) << endl;
}
