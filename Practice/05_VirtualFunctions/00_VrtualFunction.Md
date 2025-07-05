✅ 1. What is a virtual function in C++?
=================================================
🔹Answer:
A virtual function is a member function declared with the virtual keyword in a base class and meant to be overridden in derived classes. It enables runtime polymorphism, allowing function calls to be resolved dynamically using the vtable mechanism.

✅ 2. What is a vtable and vptr? How are they related to virtual functions?
==============================================================================
🔹Answer:
vtable (Virtual Table):
     A compiler-generated table of function pointers for virtual functions in a class.

vptr:
     A hidden pointer in every object of a class with virtual functions. It points to the class's vtable.

When a virtual function is called via a base class pointer/reference, the vptr guides the call to the correct function from the vtable — enabling dynamic dispatch.

✅ 3. How does the compiler generate vtable and vptr?
=======================================================================================
🔹Answer:
At compile time:
    01. A vtable is created for each class with virtual functions.
    02. Every object of such a class includes a hidden vptr set at construction to
        point to the class’s vtable.
    03. During a virtual call, the compiler generates code to:
        Fetch the vptr.
        Index into the vtable.
        Call the function pointer.

✅ 4. Can a constructor be virtual? If not, why?
=======================================================================================
🔹Answer:
        No, a constructor cannot be virtual.

🔹Reason:
            Constructors initialize the vptr itself.

At the time of base class constructor execution, the derived class part isn’t yet constructed — so calling virtual methods may lead to undefined behavior.

However, destructors should be virtual if the class is meant to be base class for polymorphic deletion.

✅ 5. What happens if a base class has a non-virtual destructor?
=======================================================================================
🔹Answer:
If a base class has a non-virtual destructor, deleting a derived object via a base class pointer leads to undefined behavior. Only the base destructor is called — the derived destructor is skipped, potentially causing resource leaks.

#include<iostream>
using namespace std;
struct Base {

public:
    Base() {
        
        cout<<"In base class constructor"<<endl;
    }
  ~Base(){
     
     cout<<"In base class destructore"<<endl;
 }
};

struct Derived : Base {
    int* data;
    Derived() : data(new int[100]) {
        cout<<"In derived class constructor"<<endl;
        
    }
    ~Derived() { 
        
        cout<<"In derived class destructore"<<endl;
        delete[] data;
        }
};

int main() {
    Base* obj = new Derived();
    delete obj;
    
   // Derived* d1 = new Base();
    //delete d1;
    
    return 0;
}

output
=============
In base class constructor
In derived class constructor
In base class destructore

🔹Fix:
Declare destructors as virtual in polymorphic base classes

✅ 6. Can virtual functions be static?
====================================================================================
🔹Answer:
No. static functions are not tied to an instance (no this pointer) and are resolved at compile time. virtual implies dynamic dispatch based on object’s runtime type — which contradicts static

✅ 7. What is pure virtual function and abstract class?
====================================================================================
🔹Answer:
A pure virtual function is declared like this:

virtual void f() = 0;


01. A class containing at least one pure virtual function is an abstract class.
02. Objects of abstract classes cannot be instantiated.
03. Must be overridden in derived classes unless derived is also abstract.

✅ 8. Can you override a non-virtual function?
===================================================================================
🔹Answer:
Yes, syntactically — but it doesn’t behave polymorphically.

class Base { void foo(); };
class Derived : public Base { void foo(); }; // This hides, not overrides

To ensure override behavior, base function must be virtual.

✅ 9. How does dynamic dispatch work under the hood?
=======================================================================================

Base* b = new Derived();
b->func(); // dynamic dispatch


Internally:
    01. b points to Derived object.
    02. b->vptr points to Derived’s vtable.
    03. The function pointer in the vtable is resolved at runtime and invoked.

✅ 10. Can destructors be pure virtual? If yes, how is it useful?
=======================================================================================
🔹Answer:
Yes. A pure virtual destructor can enforce abstract behavior:

class Base {
public:
    virtual ~Base() = 0; // pure virtual destructor
};
Base::~Base() { /* must provide definition */ }


This forces the class to be abstract while still allowing proper destruction.

✅ 11. How can you ensure overriding is correct at compile time?
======================================================================================

🔹Answer:
Use the override keyword:

class Base { virtual void foo(); };
class Derived : public Base {
    void foo() override;  // ensures signature matches
};
The compiler throws an error if foo() is incorrectly overridden (e.g., wrong signature).

✅ 12. Can virtual functions be overloaded?
=======================================================================================
🔹Answer:
Yes. You can have multiple functions with the same name but different signatures — virtual or not.

class A {
public:
    virtual void foo();
    virtual void foo(int);
};


Overloading works with different parameter lists. But note: overloading and overriding are different concepts.

✅ 13. Virtual function call inside constructor/destructor — what's the behavior?
=======================================================================================
🔹Answer:
In constructors and destructors, virtual dispatch is disabled — calls are resolved using the current class's version, not derived.

🔹Why?
Because the object is not fully constructed or has begun destruction.

✅ 14. How do you disable virtual dispatch explicitly?
=======================================================================================
🔹Answer:
You can call the function using scope resolution:

b->Base::func(); // calls base version, not virtual





✅ 1. Memory Layout Diagram (vptr + vtable)
=======================================================================================
class Base {
public:
    virtual void show() { std::cout << "Base\n"; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived\n"; }
    virtual void onlyInDerived() { std::cout << "Derived only\n"; }
};


🧠 Object Memory Layout (simplified)
------------------------------------------
Assuming :
            Derived obj;

-------------------------
| vptr (points to vtable)|
-------------------------
|        Base members   |
-------------------------
|      Derived members  |
-------------------------


🧠 Derived's vtable (simplified layout)
----------------------------------------
Derived_vtable:
+----------------------------+
| &Derived::show             |  // overrides Base::show
| &Derived::~Derived         |  // destructor
| &Derived::onlyInDerived    |  // own virtual
+----------------------------+


Base class’s vtable would only contain:
----------------------------------------------
Base_vtable:
+----------------------------+
| &Base::show                |
| &Base::~Base               |
+----------------------------+


vptr inside the object points to the correct vtable at runtime — enabling dynamic dispatch.

