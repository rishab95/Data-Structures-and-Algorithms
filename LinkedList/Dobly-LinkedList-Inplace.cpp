#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};
Node *last = NULL;

void insert(Node *head,int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		temp->prev = NULL;
	}
	else
	{
		last->next = temp;
		temp->prev = last;
	}
	last = temp;
}

void print(Node *head)
{
	Node* temp = new Node();
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	Node* headA = NULL;
	int ch, d;
	while (true)
	{
		cin >> ch;
		if (ch == 0)
		{
			break;
		}
		cout << "Enter No ";
		cin >> d;
		insert(headA ,d);
		print(headA);
	}
	Node *front = headA, *back = last;
	Node *temp = new Node();

	while (front->next != back && front != back)
	{
		temp = front->next;
		front->next = back;
		back->next = temp;
		back = back->prev;
		back->next = NULL;
	}
	print(headA);
	
	return 0;
}
