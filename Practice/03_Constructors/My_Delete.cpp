class Person {
    string name;
public:
    Person(string n) : name(n) {}

    // Copy Constructor
    Person(const Person other) {
        cout << "Copy constructor called\n";
        name = other.name;
    }
};

int main() {
    Person p1("Anil");
    Person p2 = p1;  // Calls copy constructor
}

