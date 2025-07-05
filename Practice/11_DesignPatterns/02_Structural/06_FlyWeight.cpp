/*
✅ 5. Flyweight Pattern
🔸Use Case: Save memory by reusing objects with shared state
Example: A text editor renders millions of characters — share common glyphs.

*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Glyph {
    char symbol;
public:
    Glyph(char c) : symbol(c) {}
    void draw(int fontSize) {
        cout << "Drawing '" << symbol << "' at size " << fontSize << endl;
    }
};

class GlyphFactory {
    unordered_map<char, Glyph*> glyphs;
public:
    Glyph* get(char c) {
        if (!glyphs[c])
            glyphs[c] = new Glyph(c);
        return glyphs[c];
    }
};

int main() {
    GlyphFactory factory;

    // Shared glyphs, different font sizes
    Glyph* a1 = factory.get('A');
    Glyph* a2 = factory.get('A');
    a1->draw(12);
    a2->draw(18);  // Same object, smaller memory footprint
}
