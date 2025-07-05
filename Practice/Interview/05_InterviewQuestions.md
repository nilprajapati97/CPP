#include <iostream>

struct One{

    void doSomething1(){};
    void doSomething2(){};

};

struct Two: public One {
    
    void doSomething3(){};

};

void doSomething(const One &one){
    
    One.doSomething3();

}
	
int main()
{
    Two two;
    
    doSomething(two);
    
    return 1;
}


Mistakes in the Code and How to Fix Them
Your code has two main issues:

-> Incorrect syntax in doSomething function:
    -: One.doSomething3(); is invalid because One is a type, not an object.
    -: Even if doSomething accepts Two, it only sees it as One, and One does not have doSomething3().
-> Slicing Problem in Object Passing (if passed by value)
    -: Though not occurring here since One& is used, if we passed by value (One one instead of const One& one), it would cause object slicing, meaning doSomething3() would be lost.

void doSomething(const Two &two) {  // ✅ Corrected function
    two.doSomething3();
}

✅ Solution 2: Use Dynamic Casting (If Polymorphism is Needed)
========================================================================
If you must use One&, make One a base class with virtual functions, then use dynamic_cast.

#include <iostream>

struct One {
    virtual ~One() = default; // Virtual destructor for polymorphism
    void doSomething1() {};
    void doSomething2() {};
};

struct Two : public One {
    void doSomething3() { std::cout << "doSomething3 called\n"; };
};

void doSomething(const One &one) {

    const Two* two = dynamic_cast<const Two*>(&one); // Attempt to cast

    if (two)
    {
        two->doSomething3(); // ✅ Safe call if cast succeeds
    }
    else
    {
        std::cout << "Invalid cast, object is not Two\n";
    }
}

int main() {
    Two two;
    doSomething(two); // ✅ Will print "doSomething3 called"
    return 0;
}

Issue	                                            Fix
-------------------------------------------------------------------------------------------
One.doSomething3(); is invalid	                    Use two.doSomething3(); (fix parameter type)
Function doesn’t see doSomething3()	                Use dynamic_cast if keeping One&
If passed by value, it would cause object slicing	Pass by reference (const One&) to avoid slicing