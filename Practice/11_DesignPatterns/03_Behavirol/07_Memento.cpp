
/*

✅ 7. Memento Pattern
===================================================
Use Case: Undo/Redo functionality (e.g., in a text editor)

+------------+      +------------+     +-------------+
| Originator | <--> | Memento    |     | Caretaker   |
+------------+      +------------+     +-------------+
| -state     |      | +getState()|     | -memento    |
| +save()    |      |            |     | +backup()   |
| +restore() |      +------------+     | +undo()     |
+------------+                         +-------------+


*/

#include <iostream>
#include <string>
using namespace std;

class Memento {
    string state;
public:
    Memento(string s) : state(s) {}
    string getState() const { return state; }
};

class Editor {
    string content;
public:
    void write(string s) { content += s; }
    Memento save() { return Memento(content); }
    void restore(const Memento& m) { content = m.getState(); }
    void show() { cout << content << endl; }
};

int main() {
    Editor editor;
    editor.write("Hello ");
    auto saved = editor.save();
    editor.write("World!");
    editor.show();      // Hello World!
    editor.restore(saved);
    editor.show();      // Hello
}
