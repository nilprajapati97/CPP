/*
Use Case: Lazy loading / access control
Example: Only load a heavy image from disk when it's actually needed.


*/

#include <iostream>
using namespace std;

class Image
{
public:
    virtual void display() = 0;
};

class RealImage : public Image
{
    string filename;

public:
    RealImage(string fname) : filename(fname)
    {
        cout << "Loading image: " << filename << endl; // Simulate heavy loading
    }
    void display() override
    {
        cout << "Displaying image: " << filename << endl;
    }
};

class ProxyImage : public Image
{
    string filename;
    RealImage *real = nullptr;

public:
    ProxyImage(string fname) : filename(fname) {}
    void display() override
    {
        if (!real)
            real = new RealImage(filename); // Lazy initialization
        real->display();
    }
};

int main()
{
    ProxyImage img("profile.jpg");
    cout << "Proxy created. Image not loaded yet.\n";

    img.display(); // Loads and displays
    img.display(); // Just displays
}
