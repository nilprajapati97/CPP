The statement using namespace std; brings all identifiers (classes, functions, constants, etc.) from the C++ Standard Namespace (std) into the current scope.

Here is a categorized list of major functions, classes, and components available in namespace std.

✅ 1. I/O Functions
======================================================================================================
From <iostream>, <iomanip>, <fstream>:


cin, cout, cerr, clog, endl, flush, setw, setprecision
getline, ws
✅ 2. String Functions
======================================================================================================
From <string>:


std::string, std::wstring
to_string, stoi, stol, stoul, stof, stod
✅ 3. Math Functions
======================================================================================================
From <cmath>:


abs, fabs, floor, ceil, round, trunc
pow, sqrt, log, log10, exp
sin, cos, tan, asin, acos, atan
hypot, fmod, remainder

✅ 4. Utility Functions
======================================================================================================
From <utility>, <functional>:

move, forward, swap, pair, make_pair
bind, function, ref, cref

✅ 5. Memory Management
======================================================================================================
From <memory>:


unique_ptr, shared_ptr, weak_ptr, make_shared, make_unique
allocator

✅ 6. Type Traits and Type Info
======================================================================================================
From <type_traits>, <typeinfo>:


is_same, is_integral, remove_reference, decay
typeid, type_info

✅ 7. Containers
======================================================================================================
From <vector>, <list>, <map>, etc.:


vector, list, deque, set, multiset
map, multimap, unordered_map, stack, queue, priority_queue

✅ 8. Algorithms
======================================================================================================
From <algorithm>:


sort, find, copy, transform, reverse, fill
accumulate, count, all_of, any_of, none_of
min, max, min_element, max_element

✅ 9. Numerics
======================================================================================================
From <numeric>:


accumulate, inner_product, partial_sum, adjacent_difference

✅ 10. Random Utilities
======================================================================================================
From <random>:


mt19937, rand, srand, uniform_int_distribution, normal_distribution

✅ 11. Chrono / Time
======================================================================================================
From <chrono>:


chrono::system_clock, chrono::steady_clock
chrono::duration, chrono::milliseconds
this_thread::sleep_for, sleep_until

✅ 12. Concurrency / Threads
======================================================================================================
From <thread>, <mutex>, <future>:


thread, mutex, unique_lock, lock_guard, condition_variable
async, future, promise, atomic

✅ 13. Exception Handling
======================================================================================================
From <stdexcept>, <exception>:


exception, runtime_error, logic_error, invalid_argument
throw_with_nested, rethrow_if_nested

✅ 14. Regular Expressions
======================================================================================================
From <regex>:


regex, smatch, regex_match, regex_search, regex_replace

✅ 15. Filesystem (C++17+)
======================================================================================================
From <filesystem>:


filesystem::path, exists, create_directory, remove, directory_iterator
