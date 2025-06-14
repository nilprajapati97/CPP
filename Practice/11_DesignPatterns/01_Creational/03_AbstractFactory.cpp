/*
🔹 What is Abstract Factory? 🔹
===================================================================
Provides an interface for creating families of related or dependent products without specifying their concrete classes.
This lets you keep your code independent of the actual product subclasses.

🔹 C++ Example 🔹
---------------------------------------------------------------------------
Let's say we have Buttons and Windows as products in two different families (say Mac and Windows OS).
*/


#include <iostream>
using namespace std;

// Button base class
// This serves as the abstract product for Buttons.
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};


// Window base class
// This serves as the abstract product for Windows.
class Window {
public:
    virtual void render() = 0;
    virtual ~Window() = default;
};


// 🔹 Concrete Product: Mac 🔹

// Mac Button
class MacButton : public Button {
public:
    void render() override {
        cout << "Mac Button rendered." << endl;
    }
};


// Mac Window
class MacWindow : public Window {
public:
    void render() override {
        cout << "Mac Window rendered." << endl;
    }
};


// 🔹 Concrete Product: Windows 🔹

// Windows Button
class WinButton : public Button {
public:
    void render() override {
        cout << "Windows Button rendered." << endl;
    }
};


// Windows Window
class WinWindow : public Window {
public:
    void render() override {
        cout << "Windows Window rendered." << endl;
    }
};


// 🔹 Abstract Factory 🔹

// GUIFactory base class
// This is the abstract factory that can create related products together.
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Window* createWindow() = 0;
    virtual ~GUIFactory() = default;
};


// Mac factory
// Concrete factory for Mac products
class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }
    Window* createWindow() override {
        return new MacWindow();
    }
};


// 🔹 Concrete Factories 🔹

// Windows factory
// Concrete factory for Windows products
class WinFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WinButton();
    }
    Window* createWindow() override {
        return new WinWindow();
    }
};


// 🔹 Client 🔹
// This is where we use the abstract factory to create products.
int main()
{
    // Create Mac products
    GUIFactory* macFactory = new MacFactory();
    Button* macBtn = macFactory->createButton();
    Window* macWin = macFactory->createWindow();

    macBtn->render();
    macWin->render();

    delete macBtn;
    delete macWin;
    delete macFactory;

    // Create Windows products
    GUIFactory* winFactory = new WinFactory();
    Button* winBtn = winFactory->createButton();
    Window* winWin = winFactory->createWindow();

    winBtn->render();
    winWin->render();

    delete winBtn;
    delete winWin;
    delete winFactory;

    return 0;
}

/*
Output
---------------------------
Mac Button rendered.
Mac Window rendered.
Windows Button rendered.
Windows Window rendered.

🔹 Summary 🔹
===================================================================
✅ Provides a way to create families of related products without specifying their concrete classes.
✅ Helps make code more flexible and independent of platform-specific details.
✅ Open for adding new product families without changing existing code.
*/
