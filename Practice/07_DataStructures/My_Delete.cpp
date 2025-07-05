#include<iostream>
using namespace std;
struct Node {
	
	int data;
	Node * next;
	Node(int val):data(val),next(nullptr){}
};

void addMiddle(Node*& head, int val)
{
	Node* NewNode = new Node(val);
	if(!head ||head->data >= val)
	{
	  NewNode->next = head;
	  head = NewNode;
	  return;
	}
	Node* temp = head;

	while(temp->next && temp->next->data < val)
	{
		temp = temp->next;
	}

	NewNode->next = temp->next;
	temp->next    = NewNode;

}

void display(Node* head)
{
	Node* temp = head;
	while(temp)
	{

		//cout<< temp->data << " -> "<<"A->" <<temp<<"=> "<<endl;  //address print for reverse link
		cout<< temp->data << " ->" ;
		temp = temp->next;
	
	}
	cout<<"NULL"<<endl;

}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse link
        prev = current;        // Move prev forward
        current = next;        // Move current forward
    }
    
    return prev; // New head of reversed list
}
int main()
{
	Node* head = nullptr;
        addMiddle(head , 10);
        addMiddle(head , 20);
        addMiddle(head , 30);
        addMiddle(head , 40);
        addMiddle(head , 50);

        display(head);

	addMiddle(head , 15);
        addMiddle(head , 25);
        addMiddle(head , 35);
        addMiddle(head , 45);

	display(head);

        head = reverseList(head);
	
	display(head);



}
