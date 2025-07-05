/*
✅ 10. Visitor Pattern
===================================================
Use Case: Add operations to different objects (e.g., TaxCalculator for items)

        +------------------+
        | Visitor          | ◄──── Interface
        +------------------+
        | +visit(Item)     |
        +------------------+
              ▲
              |
     +------------------+
     | TaxCalculator    |
     +------------------+
     | +visit(Item)     |
     +------------------+

+------------------+     +------------------+
| Item             |◄────|  Book            |
+------------------+     +------------------+
| +accept(Visitor) |     | +getName()       |
+------------------+     +accept(visitor){} |
                         +------------------+


*/

#include <iostream>
using namespace std;

class Item;
class Visitor {
public:
    virtual void visit(Item* item) = 0;
};

class Item {
public:
    virtual void accept(Visitor* v) = 0;
    virtual string getName() = 0;
};

class Book : public Item {
public:
    void accept(Visitor* v) override { v->visit(this); }
    string getName() override { return "Book"; }
};

class TaxCalculator : public Visitor {
public:
    void visit(Item* item) override {
        cout << "Calculating tax for " << item->getName() << endl;
    }
};

int main() {
    Book book;
    TaxCalculator calc;
    book.accept(&calc);
}
