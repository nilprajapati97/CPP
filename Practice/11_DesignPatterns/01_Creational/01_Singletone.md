Singleton Design Pattern
====================================================================================================

💡 What is the Singleton Design Pattern?

The Singleton Pattern ensures that:
    ✅ Only one instance of a class is created throughout the lifetime of the application.
    ✅ The instance is globally accessible (through a well-defined access point).
    ✅ It provides controlled access to the single instance (e.g. lazy initialization, thread safety).


⚙ When to Use Singleton?
=========================
-:  When you want exactly one object to coordinate actions (e.g. Logger, Configuration Manager, Driver manager, Cache).
-:  When creating multiple instances would waste resources or cause issues (e.g. multiple database connection pools).

📝 Key Characteristics
=========================
-:  Private constructor (prevents creating objects directly).
-:  Static pointer/reference to the single instance.
-:  Public static method to provide access to the instance (usually named getInstance()).

📌 UML Diagram
=================================
 ┌─────────────────────┐
 │    Singleton         │
 ├─────────────────────┤
 │ - instance: Singleton      │  (static private variable)
 ├─────────────────────┤
 │ + getInstance(): Singleton │ (static method to access instance)
 │ - Singleton()              │ (private constructor)
 └─────────────────────┘



-:Implementation of the Singleton Pattern In C++
====================================================
    The Singleton pattern is a creational design pattern in C++ that ensures a class has only one 
instance and provides a global point of access to that instance. It is used when you want to 
control the instantiation of a class to ensure that there's a single instance throughout the
lifetime of your application.

Below is an example implementation of the Singleton pattern in C++:

#include <iostream>

class Singleton {
public:
    // Static method to access the singleton instance
    static Singleton& getInstance()
    {
        // If the instance doesn't exist, create it
        if (!instance) {
            instance = new Singleton();
        }
        return *instance;
    }

    // Public method to perform some operation
    void someOperation()
    {
        std::cout
            << "Singleton is performing some operation."
            << std::endl;
    }

    // Delete the copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent external instantiation
    Singleton()
    {
        std::cout << "Singleton instance created."
                  << std::endl;
    }

    // Private destructor to prevent external deletion
    ~Singleton()
    {
        std::cout << "Singleton instance destroyed."
                  << std::endl;
    }

    // Private static instance variable
    static Singleton* instance;
};

// Initialize the static instance variable to nullptr
Singleton* Singleton::instance = nullptr;

int main()
{
    // Access the Singleton instance
    Singleton& singleton = Singleton::getInstance();

    // Use the Singleton instance
    singleton.someOperation();

    // Attempting to create another instance will not work
    // Singleton anotherInstance; // This line would not
    // compile

    return 0;
}


Output
========
Singleton instance created.
Singleton is performing some operation.


-: Below is the explanation of the above code:
=============================================================================
01. We have a Singleton class with a private constructor and a private destructor, ensuring that the class can only be instantiated and destroyed 
    from within the class itself.
02. The getInstance method is static and provides access to the single instance of the Singleton class. It uses lazy initialization, 
    meaning it creates the instance only when getInstance is called for the first time. Subsequent calls return the existing instance.
03. We delete the copy constructor and assignment operator to prevent copying of the Singleton instance, ensuring there's only one instance.
   In the main function, we demonstrate how to access and use the Singleton instance. Attempting to create another instance using the regular constructor is prevented because the constructor is private.
When you run this program, you'll see that only one instance of the Singleton is created, and attempting to create another instance is prevented. The Singleton instance is accessed through the getInstance method, making it globally accessible within your codebase.



Below is the explanation of the above code:

We have a Singleton class with a private constructor and a private destructor, ensuring that the class can only be instantiated and destroyed from within the class itself.
The getInstance method is static and provides access to the single instance of the Singleton class. It uses lazy initialization, meaning it creates the instance only when getInstance is called for the first time. Subsequent calls return the existing instance.
We delete the copy constructor and assignment operator to prevent copying of the Singleton instance, ensuring there's only one instance.
In the main function, we demonstrate how to access and use the Singleton instance. Attempting to create another instance using the regular constructor is prevented because the constructor is private.



Key Components:
====================
-: Singleton Class:
        This is the class that you want to make a singleton. It has a private constructor, private destructor, and a private static member 
        variable to hold the single instance of the class.
-: Static Member Variable: 
        This is a private static member variable within the Singleton class that holds the single instance of the class. It is usually initialized
        to nullptr or an instance of the class itself.
-: Static Method (getInstance):
        A public static method within the Singleton class called getInstance. This method is responsible for creating the instance if it doesn't exist 
        or returning the existing instance if it does. It ensures that there's only one instance of the class.
-: Delete Copy Constructor and Assignment Operator:
        To prevent copying of the Singleton instance, the copy constructor and assignment operator should be deleted within the Singleton class.


+-------------------------+
|        Singleton        |
+-------------------------+
| - instance : Singleton* |
+-------------------------+
| + getInstance() : Singleton& |
| + someMethod() |
+-------------------------+

      |
      ▼ (Lazy Initialization)
      |
+---------+
| Instance |
+---------+



The Singleton class:
========================================
Private static instance — holds its own instance.
Public static getInstance() — controls the instantiation (creates if it doesn’t exist).
The flow shows Lazy Initialization — when getInstance() is first called, the instance is created, then subsequently reuse it.


Above diagram of singleton pattern works as follows:
=========================================================
-:Initialization:
        The static member variable in the Singleton class is initialized to nullptr (or an instance of the class) when the program starts.

-:First Access (Lazy Initialization):
        When the getInstance method is called for the first time, it checks if the static member variable is nullptr. If it is, it creates a new instance of the Singleton class using its private constructor. If it's not nullptr, it returns the existing instance.

-:Subsequent Accesses:
        For all subsequent calls to getInstance, the method simply returns the existing instance created during the first access.
-:Usage:
        Clients access the Singleton instance by calling getInstance() and can then use the methods and data members of the Singleton as needed.


Note -:
============
In the diagram above, Singleton is the Singleton class, instance is the static member variable holding the single instance, 
and getInstance() is the static method responsible for managing access to that instance.
