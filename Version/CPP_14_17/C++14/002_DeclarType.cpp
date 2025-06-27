/*#include <iostream>
using namespace std;

int main()
{
int x = 42;
decltype(auto) getX() {
    return x;
}

}

Explanation: decltype(auto) deduces exact type 
(including reference if needed) — useful when forwarding or returning expressions.

*/
#include <iostream>
using namespace std;

int main()
{
    int x = 42;

    auto getX = [&]() -> decltype(auto) {
        return x;
    };

    cout << "Value of x: " << getX() << endl;

    getX() = 99;

    cout << "Modified x: " << getX() << endl;

    return 0;
}
