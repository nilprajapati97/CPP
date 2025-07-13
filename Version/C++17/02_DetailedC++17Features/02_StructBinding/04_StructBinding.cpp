/*
✅ Option 2: Custom struct with std::tuple_size, get<>, etc.
To support structured bindings with non-aggregate types, define:
==========================================================================
    std::get<N>()

    std::tuple_size<>

    std::tuple_element<>

    <details> <summary>Example (Advanced):</summary>
*/

// 01 Faulty Code
//=================================
/*
#include <tuple>
#include <iostream>

struct Point {
    int x, y;
};

// Enable structured binding support for Point
namespace std {
    template <>
    struct tuple_size<Point> : std::integral_constant<std::size_t, 2> {};

    template <>
    struct tuple_element<0, Point> {
        using type = int;
    };

    template <>
    struct tuple_element<1, Point> {
        using type = int;
    };
}

// Define get<>() for structured bindings
int& get<0>(Point& p) noexcept { return p.x; }
const int& get<0>(const Point& p) noexcept { return p.x; }

int& get<1>(Point& p) noexcept { return p.y; }
const int& get<1>(const Point& p) noexcept { return p.y; }

int main() {
    Point pt{10, 20};

    auto [x, y] = pt; // C++17 structured binding

    std::cout << "x = " << x << ", y = " << y << "\n";
}
*/
/*

✅ Fix: Ensure get() returns a const reference when passed a const Point&
=================================================================================
Update both get<>() overloads as follows:

✅ Why This Works
===============================================================================
Structured bindings bind to references by default:

        auto [x, y] = pt;        // x and y are references
        auto const [x, y] = pt;  // x and y are const references
        So your get<>() must return:

int& for Point&

const int& for const Point&
*/

// 02 Solution Currected code
//==================================
#include <tuple>
#include <iostream>

struct Point {
    int x, y;
};

// Structured binding support must go into same namespace as `Point`
namespace std {
    template <>
    struct tuple_size<Point> : std::integral_constant<std::size_t, 2> {};

    template <>
    struct tuple_element<0, Point> {
        using type = int;
    };

    template <>
    struct tuple_element<1, Point> {
        using type = int;
    };
}

// Declare get<>() inside the **global namespace** where Point lives
template <std::size_t N>
decltype(auto) get(Point& p) {
    if constexpr (N == 0) return (p.x);
    else if constexpr (N == 1) return (p.y);
    else static_assert(N < 2, "Index out of bounds for Point");
}

template <std::size_t N>
decltype(auto) get(const Point& p) {
    if constexpr (N == 0) return (p.x);
    else if constexpr (N == 1) return (p.y);
    else static_assert(N < 2, "Index out of bounds for Point");
}

int main() {
    Point pt{10, 20};
    //auto  [x, y] = pt;  // Structured binding
    /*
    error: binding reference of type ‘std::tuple_element<1, Point>::type&’ 
    {aka ‘int&’} to ‘const int’ discards qualifier
    */
    auto const [x, y] = pt;  // Structured binding
    std::cout << "x = " << x << ", y = " << y << "\n";
}
