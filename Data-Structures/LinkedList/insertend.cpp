#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
//node* head = NULL;

node* insertend(node* head,int data)
{
	node* trav;
	node* newnode = new node();
	newnode->data = data;
	//newnode->next = NULL;

	if (head == NULL)
	{
		newnode->next = NULL;
		head = newnode;
	}
	else
	{
		trav = head;
		while (trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = newnode;
		newnode->next = NULL;
	}
	return head;
}

void print(node* head)
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data<<" ";
		temp = temp->next;
	}
}

int main()
{
	node* head = NULL;
	head = insertend(head, 1);
	print(head);
	cout << "\n";
	head = insertend(head, 2);
	print(head);
	cout << "\n";
	head = insertend(head, 3);
	print(head);
	cout << "\n";

	return 0;
}
