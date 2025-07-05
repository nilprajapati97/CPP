1. Difference between Composition and inheritance . when do u prefer composition over inheritance.

1. Inheritance
==================
Inheritance is a mechanism where a class (derived) acquires properties and behaviors from another class (base). It represents an "is-a" relationship.

#include <iostream>

class Animal {
public:
    void makeSound() { std::cout << "Animal Sound" << std::endl; }
};

class Dog : public Animal {  // Dog "is-a" type of Animal
public:
    void bark() { std::cout << "Woof!" << std::endl; }
};

int main() {
    Dog d;
    d.makeSound();  // Inherited method
    d.bark();       // Dog's own method
}

🔹 When to Use Inheritance?
✔ When objects follow an "is-a" relationship (e.g., Dog is an Animal).
✔ When you need to extend existing behavior.
✔ When you need polymorphism (virtual functions and method overriding).

🔴 Problems with Inheritance
Tight coupling: The child class depends on the parent.
Breaks encapsulation: Changes in the base class affect all derived classes.
Not flexible: If the base class changes, all derived classes must be updated.


2. Composition
=============================================
Composition is a design principle where one class contains an instance of another class, forming a "has-a" relationship.

#include <iostream>

class Engine {
public:
    void start() { std::cout << "Engine Started" << std::endl; }
};

class Car {
private:
    Engine engine;  // Car "has-a" Engine
public:
    void startCar() { 
        engine.start(); 
        std::cout << "Car Started" << std::endl; 
    }
};

int main() {
    Car c;
    c.startCar();
}

🔹 When to Use Composition?
✔ When objects follow a "has-a" relationship (e.g., Car has an Engine).
✔ When you want loose coupling (changes in Engine class won’t affect Car).
✔ When you need better flexibility & maintainability.

🔴 Problems with Composition
More boilerplate code compared to inheritance.
Might need delegation to expose the functionality of the composed object.

3. When to Prefer Composition Over Inheritance?
========================================================================

Feature	                        Inheritance ("is-a")	                Composition ("has-a")
---------------------------------------------------------------------------------------------------
Coupling	                    Tightly coupled	                        Loosely coupled
Code Reusability	            Yes, but forces hierarchy	            Yes, without hierarchy
Flexibility	                    Less flexible	                        More flexible
Encapsulation	                Less (base class affects child)	        More (changes don’t break hierarchy)
Multiple Behaviors	            Harder (single inheritance restriction)	Easier (can mix behaviors)

✅ Prefer Composition When:

You want to avoid tight coupling between classes.
You need to use multiple independent components (e.g., a Car has an Engine, Wheels, Radio).
You want to change behavior dynamically (e.g., Strategy Pattern).
You want to decouple code for better maintainability.
🚀 Prefer Inheritance When:

There is a clear "is-a" relationship.
You need polymorphism (i.e., overriding behavior dynamically).
You are designing frameworks where behavior should be extended.
