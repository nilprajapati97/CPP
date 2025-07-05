/*
Great question! The cyclic reference problem you're seeing is a classic pitfall of shared_ptr,
and understanding it is important for any advanced C++ developer. Let's break it down step-by-step 
and then explain how replacing one shared_ptr with a weak_ptr solves it.

*/

#include <memory>
#include <iostream>
using namespace std;
struct B;
struct A {
public:
    shared_ptr<B> bptr;  // shared_ptr creates a cyclic reference
    // If you want to break the cyclic reference, use weak_ptr instead
    // weak_ptr<B> bptr; // Uncomment this line to break the cycle
    A() {
        std::cout << "Constructor -A" << std::endl;
    }
    ~A() {
        std::cout << "Destructor -A" << std::endl;
    }
    
};

struct B {

public:
    //shared_ptr<A> aptr;  // shared_ptr creates a cyclic reference
    // If you want to break the cyclic reference, use weak_ptr instead
    // std::weak_ptr<A> aptr; // Uncomment this line to break the cycle 
    weak_ptr<A> aptr;  // weak_ptr breaks cyclic reference

    B() {
        std::cout << "Constructor -B" << std::endl;
    }
    ~B() {
        std::cout << "Destructor -B" << std::endl;
    }
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->bptr = b;
    b->aptr = a; // weak_ptr avoids memory leak
}

/*
Output:
Constructor -A
Constructor -B
Destructor -B
Destructor -A

Analysis:
================================================================================================================================
🔁 Problem: Cyclic Reference (Strong Reference Cycle)
In your code:

auto a = std::make_shared<A>();
auto b = std::make_shared<B>();
a->bptr = b;
b->aptr = a;


Here’s what happens:

01. a is a shared_ptr<A> → owns an object of type A
02. b is a shared_ptr<B> → owns an object of type B
03. a->bptr = b; → A now has a shared_ptr to B
04. b->aptr = a; → B now has a shared_ptr to A

This creates a strong reference cycle: A holds a shared_ptr to B, and B holds a shared_ptr to A.
This means that neither A nor B can be destroyed because their reference counts never reach zero, leading to a memory leak.

🧠 How shared_ptr Works
------------------------------------
Each shared_ptr<T> has:
    A pointer to T
    A reference count shared across all copies
    When count drops to 0 → it deletes the object.

But cyclic shared_ptr references prevent this drop, leading to leaked memory.


✅ Solution: Break Cycle with weak_ptr -: 🔓 Solution: Use weak_ptr
---------------------------------------------------------------------------------------------------
To break the cycle, you can replace one of the shared_ptrs with a weak_ptr.
This allows you to maintain a non-owning reference to the object without affecting its lifetime.

Replace one of the shared_ptrs with a weak_ptr:

struct B {
    std::weak_ptr<A> aptr; // <-- weak_ptr here
};

🔍 Now What Happens?
    a holds b with shared_ptr → strong ownership
    b holds a with weak_ptr → non-owning reference

This means:
- a->bptr increments reference count of b
- b->aptr does not increment reference count of a
-aptr does not increment reference count

So when a and b go out of scope:
    a->bptr is destroyed → b ref count = 0 → destroy b
    b->aptr is weak → doesn’t affect a’s ref count → a also destroyed

✅ Destructors are called for both A and B, cycle is broken.
---------------------------------------------------------------------------------------------------------

📊 Memory Model Diagram
===============================================================
Before weak_ptr:
                [shared_ptr<A> a] ──> A ──> [shared_ptr<B> b] ──> B ──> [shared_ptr<A> a] (cycle)

After weak_ptr:
                [shared_ptr<A> a] ──> A ──> [shared_ptr<B> b] ──> B ──> [weak_ptr<A>] (no cycle)


🔧 Real Use-Case Analogy
---------------------------
Let’s say:
    A is a GUI widget.
    B is a controller that observes A.

B wants to observe A, but not own it. So B should hold a weak_ptr<A>.
That way if the widget is deleted, the controller doesn’t prevent cleanup.

✅ Best Practice
Use weak_ptr for back references, observers, or any non-owning relationship.

💡 Bonus: How to Use weak_ptr
To safely access the object:


    if (auto a_shared = b->aptr.lock()) {
        // use a_shared
    } else {
        // A is already destroyed
    }


*/
