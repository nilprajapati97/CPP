
/*
Ciclick dependency  - destructor not called so memory leaks

*/

#include <iostream>
#include <memory>

using namespace std;
class B;
class A
{
public:
     shared_ptr <B> p1;
    //weak_ptr<B> p1;
    A()
    {
        cout << "Constructor -A" << endl;
    }
    void set_ptr(shared_ptr<B> &ptr1)
    {
        p1 = ptr1;
    }

    ~A()
    {
        cout << "Destructor -A" << endl;
    }
};

class B
{
public:
     shared_ptr <A> p2;
    //weak_ptr<A> p2;
    B()
    {
        cout << "Constructor -B" << endl;
    }
    void set_ptr(shared_ptr<A> &ptr2)
    {
        p2 = ptr2;
    }

    ~B()
    {
        cout << "Destructor -B" << endl;
    }
};

void my_function()
{
    shared_ptr<A> objAptr(new A());
    shared_ptr<B> objBptr(new B());

    objAptr->set_ptr(objBptr);
    objBptr->set_ptr(objAptr);

    cout << "A-> use count" << objAptr.use_count() << endl;
    cout << "B-> use count" << objBptr.use_count() << endl;
}
int main()
{
    my_function();
    cout << endl;
    // Memory leak occurs here due to cyclic dependency
    // The destructors for A and B are never called because they hold shared pointers to each
    // other, preventing their reference counts from reaching zero.
    cout << "End of main function" << endl;
    // To avoid this, we can use weak_ptr for one of the pointers to break the cycle.
    // Uncomment the weak_ptr lines in class A and B to see how it resolves the issue
    // In that case, the destructors will be called, and no memory leak will occur
    // Note: If you use weak_ptr, you need to check if the pointer is valid
    // before accessing it, as weak_ptr does not own the object and can be null.
    return 0;
}