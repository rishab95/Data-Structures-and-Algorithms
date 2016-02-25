#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* Insert(Node* head, int data, int position)
{
	Node* newnode = new Node;
	newnode->data = data;
	newnode->next = NULL;

	if(head == NULL)
	{
		return (head = newnode);
	}

	else if(position == 0)
	{
		newnode->next = head;
		return (head = newnode);
	}

	else
	{
		int i = 1;
		Node* temp = head; // to traverse the list

		while(temp != NULL)
		{
			if(i == position)
			{
				newnode->next = temp->next;
				temp->next = newnode;
				return head;
			}
			temp = temp->next;
			i++;
		}

	}	

}
