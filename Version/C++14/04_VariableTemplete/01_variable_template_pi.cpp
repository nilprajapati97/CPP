 #include <iostream>
using namespace std;
// ✅ Variable Template: define pi for any numeric type T
template<typename T>
constexpr T pi = T(3.1415926535);

int main() {
    float f = pi<float>;       // f = 3.14159f
    double d = pi<double>;     // d = 3.1415926535
    long double ld = pi<long double>; // extended precision

    cout << "Float  pi: " << f << endl;
    cout << "Double pi: " << d << endl;
    cout << "Long double pi: " << ld << endl;

    return 0;
}
// Output:
// Float  pi: 3.14159
// Double pi: 3.1415926535
// Long double pi: 3.14159265358979323846

/*
✅ Benefits:
=============================================================================================
| Feature              | Benefit                                                           |
| -------------------- | ----------------------------------------------------------------- |
| 🧠 Type-safe         | You get `pi<float>`, `pi<double>`, etc. explicitly                |
| 🧮 Generic constants | Use in math libs, template metaprogramming                        |
| 🧼 Cleaner code      | Avoid `#define PI 3.14` or `const double pi = 3.14;` with casting |
| 🛠️ Reusable          | Define once, use with any numeric type                            |
=============================================================================================
//
1. **Type Safety**: Ensures the correct type is used for each instantiation.
2. **Code Reusability**: Define once, use with any numeric type.
3. **Maintainability**: Changes to the definition need to be made in only one place.

*/