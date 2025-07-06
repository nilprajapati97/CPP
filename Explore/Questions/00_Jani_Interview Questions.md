Interview Questions

1. Difference between Composition and inheritance . when do u prefer composition over inheritance.

2. pass by value is shallow copy /deep copy Justify.

3. #include<iostream>
void doSomething();
int main()
{
doSomething();
return 1;
}
build successful ?
 At what stage errors will be thrown

5. build successful ? what stage error will be thrown.

struct One
{
void doSomething1(){};
void doSomething2(){};
};

struct Two: public One 
{
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

----------------------------------------------------------------------------------------------------------------------------------------------------------
6. Explain virtual functions with example program 

7. modify the same program to exhibit encapsulation

8. modify the same program to include thread.

9. why join() ?

10. program - occurence of a characters in string

11. exception handling - what are the elements 

12. have you worked on optimising speed of your application - explain

13. how will you handle constructive critisicm

14. recent challenging task you faced how have you handled it 

15. what protocols you use in your application

16. Expalin CAN protocol

--------------------------------------------------------------------------------------------------------------------------------------------------------------
String; 2be reveresed... reverse string but punct should be in same place
use best datastructure 

Lambda fucntions - pass by value reference and pass a parameter - add function and execute in compiler

explain gtest
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
Expalin virtual fucntion with example program 
how many vtables and vpointer for the example program 

explain deep copy constructor with example program

encapsulation

abstraction

program to reverse the string 

what are storage classes - expalin

write singleton design pattern and explain
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
How can you prevent copying of same objects in copy constructor?
 
C++ class to store and manage 2D coordinates with x and y axis values ?
 
How can I print values of this object using cout<<obj ?


struct BigData {
	int data[1024][1024];
};
 
void f(BigData const& value){
	value.data[0][0] = 5;
}
int main() {
	BigData x;
	f(x);
	cout<<x.data[0][0]<<endl;
}
 
what is the issue with this code

#include <iostream>
#include <vector>
using namespace std;
 
class A {
private:
    int id;
 
public:
    A(int id_val) : id(id_val) {
        cout << "Constructor called for id: " << id << endl;
    }
 
    // Copy Constructor
    A(const A& other) : id(other.id) {
        cout << "Copy Constructor called for id: " << other.id << endl;
    }
 
    // Assignment Operator
    A& operator=(const A& other) {
        if (this != &other) {
            id = other.id;
            cout << "Assignment Operator called for id: " << id << endl;
        }
        return *this;
    }
 
};
 
int main() {
    A obj1(100);
    A obj2(200);
 
    vector<A> someList;
    someList.push_back(obj1);
    someList.push_back(obj2);
 
    return 0;
}
 
what will happen when push_back is called ?how memory is managed in this case. ?

#include <iostream>
using namespace std;
 
// Base class A
class A {
protected:
    int i;
 
public:
    // Default constructor for A
    A() : i(2) {
        cout << "A's Default Constructor called, i = " << i << endl;
    }
 
    // Copy constructor for A
    A(const A& other) : i(other.i) {
        cout << "A's Copy Constructor called, i = " << i << endl;
    }
 
    // Destructor for A
    virtual ~A() {
        cout << "A's Destructor called, i = " << i << endl;
    }
};
 
// Derived class B inherits from A
class B : public A {
private:
    int j;
 
public:
    B() : A(), j(3) {
        cout << "B's Default Constructor called, j = " << j << endl;
    }
 
    B(const B& other) : A(other), j(other.j) {
        cout << "B's Copy Constructor called, j = " << j << endl;
    }
    B& operator=(const B& other) {
        if (this != &other) {
            A::operator=(other);
            j = other.j;
            cout << "B's Assignment Operator called, j = " << j << endl;
        }
        return *this;
    }
 
    // Destructor for B
    ~B() {
        cout << "B's Destructor called, j = " << j << endl;
    }
};
 
int main() {
    B obj;
    A& obj1 = obj;
    cout << "obj1.i = " << obj1.i << endl;
 
    return 0;
} //order of execution what will be the output ?
 
what will happen in this case  A obj1 = obj; ?

how to prevent copy between two objects in copy assignment operator
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
reverese linkedList using recursion and iterative

trees .data structure

stack and queue datastructure expalin

how will you test private function in gtest

In what case u prefer pointers over reference

implement smartArray -> class smartArray that dynamically allocates memory  based on user input and deallocate memory
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
linkedLIst problem 1->2->3->4->5 as 1->5->2->4->3

// Function to find the first element satisfying predicate p
int firstElementSatisfyingPredicate(const std::vector<int>& arr, bool (*p)(int)) {

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
why cpp to communicate to alexa cloud why not java only . since we have alexa sdk in java also know 
 
how to do check core dump in relese versions 
 
how do u communicate with alexa cloud . what protocol u use ?
 
any security measures u follow to post . since anyone can use that API to post ?
 
how do u use gdb in a running application 
 
what is static lib and dynamic library. when a function declared in some module and u are using it in another module how do u link it in a application 
 
getting audio data is sync call or asyn call. since only after responding back with output u wull go for next session ?

program to sort an array based on the occurence 

Singleton Design Pattern - explain
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
Interprocess communication used in our application

if there is a main thread and that thread has 5 process and that process has threads. what is the difference between creating as thread and process 

how will you avoid copy ellision 

how will you avoid diamond problem without using virtual keyword

socket programming

core dump how will you know for which process there is one line command ?

how will you stop a process.

Disadvantage of virtual functions

linked list to insert numbers and reverse it

In visual studio how will you use json for debugging executables

what will happen to the objects in stack when it goes to catch block ? what will happen to the object stack

pointer will be stored where and pointer data will be stored where.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLID Principles

Principle	Key Idea	Benefits
SRP	One class, one responsibility.	Easier to understand, maintain, and test.
OCP	Open for extension, closed for modification.	Facilitates future changes and scalability.
LSP	Subtypes should be substitutable for base types.	Ensures program correctness with inheritance.
ISP	Split large interfaces into smaller ones.	Avoids implementing irrelevant methods.
DIP	Depend on abstractions, not concrete classes.	Reduces coupling and improves flexibility.

singleton 

deep copy constructor and assignment operator

Template Specialisation - stack that should work on any data type - program 

why const reference in copy constructor 

can we use pointers in the place of reference in copy constructor

can we use allocate memory using malloc instead of new in copy constructor

vector and list difference when to use what ?

what will happen if values keeps inserted to the vector ?

insert elements and then reverse a linked list 

what is the return type of printf statement

Reasons Why Static Functions Cannot Be Virtual

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Macro to find the NthLargest Bit 
How to introduce Segmentation fault

Notify and wait in threads
Second largest element in the linkedList
Merge two sorted arrays 

--------------------------------------------

weak pointers
what are the other types of lock_guard
what IPC do u use ?
when we push to talk from HMI how is the initiation happens ?
Singleton design pattern thread safe 
C++ 11 vs C++ 17

Will vtable have virtual fucntions / normal functions/ static fucntions 
static where have you implemented in your project


Interview Questions

1. Difference between Composition and inheritance . when do u prefer composition over inheritance.

2. pass by value is shallow copy /deep copy Justify.

3. #include<iostream>
void doSomething();
int main()
{
doSomething();
return 1;
}
build successful ?
 At what stage errors will be thrown

5. build successful ? what stage error will be thrown.

struct One
{
void doSomething1(){};
void doSomething2(){};
};

struct Two: public One 
{
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

----------------------------------------------------------------------------------------------------------------------------------------------------------
6. Explain virtual functions with example program 

7. modify the same program to exhibit encapsulation

8. modify the same program to include thread.

9. why join() ?

10. program - occurence of a characters in string

11. exception handling - what are the elements 

12. have you worked on optimising speed of your application - explain

13. how will you handle constructive critisicm

14. recent challenging task you faced how have you handled it 

15. what protocols you use in your application

16. Expalin CAN protocol

--------------------------------------------------------------------------------------------------------------------------------------------------------------
String; 2be reveresed... reverse string but punct should be in same place
use best datastructure 

Lambda fucntions - pass by value reference and pass a parameter - add function and execute in compiler

explain gtest
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
Expalin virtual fucntion with example program 
how many vtables and vpointer for the example program 

explain deep copy constructor with example program

encapsulation

abstraction

program to reverse the string 

what are storage classes - expalin

write singleton design pattern and explain
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
How can you prevent copying of same objects in copy constructor?
 
C++ class to store and manage 2D coordinates with x and y axis values ?
 
How can I print values of this object using cout<<obj ?


struct BigData {
	int data[1024][1024];
};
 
void f(BigData const& value){
	value.data[0][0] = 5;
}
int main() {
	BigData x;
	f(x);
	cout<<x.data[0][0]<<endl;
}
 
what is the issue with this code

#include <iostream>
#include <vector>
using namespace std;
 
class A {
private:
    int id;
 
public:
    A(int id_val) : id(id_val) {
        cout << "Constructor called for id: " << id << endl;
    }
 
    // Copy Constructor
    A(const A& other) : id(other.id) {
        cout << "Copy Constructor called for id: " << other.id << endl;
    }
 
    // Assignment Operator
    A& operator=(const A& other) {
        if (this != &other) {
            id = other.id;
            cout << "Assignment Operator called for id: " << id << endl;
        }
        return *this;
    }
 
};
 
int main() {
    A obj1(100);
    A obj2(200);
 
    vector<A> someList;
    someList.push_back(obj1);
    someList.push_back(obj2);
 
    return 0;
}
 
what will happen when push_back is called ?how memory is managed in this case. ?

#include <iostream>
using namespace std;
 
// Base class A
class A {
protected:
    int i;
 
public:
    // Default constructor for A
    A() : i(2) {
        cout << "A's Default Constructor called, i = " << i << endl;
    }
 
    // Copy constructor for A
    A(const A& other) : i(other.i) {
        cout << "A's Copy Constructor called, i = " << i << endl;
    }
 
    // Destructor for A
    virtual ~A() {
        cout << "A's Destructor called, i = " << i << endl;
    }
};
 
// Derived class B inherits from A
class B : public A {
private:
    int j;
 
public:
    B() : A(), j(3) {
        cout << "B's Default Constructor called, j = " << j << endl;
    }
 
    B(const B& other) : A(other), j(other.j) {
        cout << "B's Copy Constructor called, j = " << j << endl;
    }
    B& operator=(const B& other) {
        if (this != &other) {
            A::operator=(other);
            j = other.j;
            cout << "B's Assignment Operator called, j = " << j << endl;
        }
        return *this;
    }
 
    // Destructor for B
    ~B() {
        cout << "B's Destructor called, j = " << j << endl;
    }
};
 
int main() {
    B obj;
    A& obj1 = obj;
    cout << "obj1.i = " << obj1.i << endl;
 
    return 0;
} //order of execution what will be the output ?
 
what will happen in this case  A obj1 = obj; ?

how to prevent copy between two objects in copy assignment operator
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
reverese linkedList using recursion and iterative

trees .data structure

stack and queue datastructure expalin

how will you test private function in gtest

In what case u prefer pointers over reference

implement smartArray -> class smartArray that dynamically allocates memory  based on user input and deallocate memory
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
linkedLIst problem 1->2->3->4->5 as 1->5->2->4->3

// Function to find the first element satisfying predicate p
int firstElementSatisfyingPredicate(const std::vector<int>& arr, bool (*p)(int)) {

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
why cpp to communicate to alexa cloud why not java only . since we have alexa sdk in java also know 
 
how to do check core dump in relese versions 
 
how do u communicate with alexa cloud . what protocol u use ?
 
any security measures u follow to post . since anyone can use that API to post ?
 
how do u use gdb in a running application 
 
what is static lib and dynamic library. when a function declared in some module and u are using it in another module how do u link it in a application 
 
getting audio data is sync call or asyn call. since only after responding back with output u wull go for next session ?

program to sort an array based on the occurence 

Singleton Design Pattern - explain
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
how does two components communicate

what is cmake 

how to make two process synchronized

If a process has many threads . each thread will share what data segment ?

what is the size of virtual pointers in c++

If a class has functions like virtual functions non virtual functions and static functions in c++ The Vtable will have function pointers of what all functions ?

Implement own string class exhibit oops concepts 

how many process do u have in your applications 

Smart pointers - weak pointers 

diff btw semaphore and mutex

different types of locks - unique locks , shared locks

write a sample program for unique lock ?

write a program where a thread will read the buffer and increment the value and after 10 increment the other thread should display the data . how will you synchronize the data

I have a class to get temperature from some source . it has to notify other class whenever there is a change in temperature. how will you design the class.

---------------------------------------------------------------------------------------------
1. shared ptr, smart ptr, weak ptr
	- when and why we should use it and why not normal pointer
2. why to use lambda over function in c++
3. Write program to create shared ptr
4. Multithreding
	- when and why used in project
	- which library is there other than pthread
5. write a program for multithreading
	- in that 2 functions, one will print even numbers other will print odd numbers
6. GDB commands and name of the file which can be given as input to debug with GDB
7. Write single linked list in C++ and reverse it
	- i/p 10 20 30 40 50 60
	- o/p 60 50 40 30 20 10
8. what will happen if we will not use join for thread in main function