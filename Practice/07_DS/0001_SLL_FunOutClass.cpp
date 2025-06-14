#include <iostream>

using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Add node at the beginning
void addAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Add node at the end
void addAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Add node in the middle (after a given position)
void addAtMiddle(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data < value) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    
    addAtEnd(head, 10);
    addAtEnd(head, 20);
    addAtEnd(head, 30);
    display(head);

    addAtBeginning(head, 5);
    display(head);

    addAtMiddle(head,111);
    addAtMiddle(head,99);
    addAtMiddle(head,88);
    addAtMiddle(head,77);
    addAtMiddle(head,66);
    
    display(head);
    
    return 0;
}
