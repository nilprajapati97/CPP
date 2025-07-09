#include <iostream>
#include <optional>
using namespace std;

optional<int> find(bool ok) {
    if (ok) return 42;
    return nullopt;
}

int main() {
    auto val = find(true);
    if (val) cout << *val << endl;
}
