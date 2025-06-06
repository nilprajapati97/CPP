
/*
Ciclick dependency  - destructor n ot called so memory leaks

*/

#include <iostream>
#include <memory>

using namespace std;
class B;
class A
{
public:
    // shared_ptr <B> p1;
    weak_ptr<B> p1;
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
    // shared_ptr <A> p2;
    weak_ptr<A> p2;
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
    return 0;
}