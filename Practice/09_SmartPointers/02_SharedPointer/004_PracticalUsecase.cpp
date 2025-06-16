/*
🔹Practical Use Case🔹:
---------------------------
Picture you’re developing a game with many game entities (like players, weapons, or power-ups)
 — multiple components may need to hold a reference to the same object.

Using std::shared_ptr lets you safely share ownership without worried about double deletion 
or invalid pointers.

*/

#include <iostream>
#include <memory>
using namespace std;

class Player {

private:
    string name;
public:
    Player(string name) : name(name) {
        cout << "Player " << name << " constructed." << endl;
    }
    ~Player(){
        cout << "Player " << name << " destroyed." << endl;
    }

    void print(){
        cout << "Player: " << name << endl;
    }
};

void teamMember(shared_ptr<Player> player) {
    // This teamMember shares ownership of the player
    cout << "Team member is accessing player…" << endl;
    player->print();
}

int main()
{
    // Create a shared_ptr to a new player
    shared_ptr<Player> player = make_shared<Player>("Alice");

    // Share it with another teamMember
    teamMember(player);

    // The player will be destroyed after the last shared_ptr goes out of scope
    cout << "Last shared_ptr is going out of scope…" << endl;

    return 0;
}
/*
Output
----------
Player Alice constructed.
Team member is accessing player…
Player: Alice
Last shared_ptr is going out of scope…
Player Alice destroyed.


🔹Summary🔹:
✅ std::shared_ptr is useful when:
    -: Multiple entities need to share ownership of a resource.
    -: The object should be freed automatically when there’s no more owner.

✅ Use:
    -: std::shared_ptr<Player> p = std::make_shared<Player>("Alice");

// p can be passed, or copy-constructed safely.
// The object is freed when the last shared_ptr goes out of scope.

*/


