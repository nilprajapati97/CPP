#include <iostream>

using namespace std;

// Define a Node structure
struct Node {
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
	public:
		Node* head;

		LinkedList() : head(nullptr) {}

		// Add node at the beginning
		void addAtBeginning(int value) {
			Node* newNode = new Node(value);
			newNode->next = head;
			head = newNode;
		}

		// Add node at the end
		void addAtEnd(int value) {
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
		void addAtMiddle(int value, int position) {
			if (position <= 0) {
				addAtBeginning(value);
				return;
			}
			Node* newNode = new Node(value);
			Node* temp = head;
			for (int i = 0; temp != nullptr && i < position - 1; i++) {
				temp = temp->next;
			}
			if (!temp) {
				cout << "Position out of bounds, adding at end.\n";
				addAtEnd(value);
				return;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}

		// Display the linked list
		void display() {
			Node* temp = head;
			while (temp) {
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "NULL\n";
		}
};

int main() {
	LinkedList list;

	list.addAtEnd(10);
	list.addAtEnd(20);
	list.addAtEnd(30);
	list.display();

	list.addAtBeginning(5);
	list.display();

	list.addAtMiddle(15, 2);
	list.display();

	return 0;
}
