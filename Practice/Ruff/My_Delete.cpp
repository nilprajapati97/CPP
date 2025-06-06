#include<iostream>
using namespace std;

class Node {

	public:	
		int  data;
		Node *next;

		Node(int val): data(val),next(nullptr)
		{
	
		}

};

void AddMiddle(Node *&head , int val)
{
	Node *NewNode = new Node(val);

	if(!head || head->data >= val)
	{
		NewNode->next = head;
		head = NewNode;

		return;
	}
	
	else
	{
		Node *temp = head;
		while(temp->next && temp->next->data < val)
		{
			temp = temp->next;
		}

		NewNode->next = temp->next;
		temp->next    = NewNode;
	}
}
void Display(Node *head)
{
  Node *temp = head;

  while(temp)
  {
  	cout<< temp->data <<"->";
	temp = temp->next;
  
  }
  cout<<"NULL"<<endl;



}
Node * reverse(Node *head)
{
	Node* prev = nullptr;
	Node* current = head;
	Node* next = nullptr;

	while(current != nullptr)
	{
		next= current->next;
		current->next = prev;
		prev= current;
		current = next;
	}
	return prev;
}
int main()

{

        Node*  head =nullptr;

	AddMiddle(head,10);
	AddMiddle(head,20);
	AddMiddle(head,30);
	AddMiddle(head,40);
	AddMiddle(head,50);
	AddMiddle(head,60);
	
	Display(head);
	head =reverse(head);
	Display(head);
	
	AddMiddle(head,17);
	AddMiddle(head,23);
	AddMiddle(head,36);
	AddMiddle(head,48);
	AddMiddle(head,55);
	Display(head);
	head =reverse(head);
	Display(head);
	
       cout<<endl<<endl;

	return 0;
}
