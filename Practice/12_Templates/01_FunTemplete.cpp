#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
	return a + b;
}

int main() {
	cout << add<int>(3, 4) << endl;     // Output: 7
	cout << add<double>(2.5, 4.3) << endl; // Output: 6.8
	return 0;
}

