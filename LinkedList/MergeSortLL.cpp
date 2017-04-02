#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
void insert(node **head, int);
void print(node *head);
void swap(node *a, node *b);
void sort(node *head);
node *reverse(node *head);
int mid(node *head);
node *frontbacksplit(node *head);

int main()
{
	node *head = NULL;
	cout << "Linked List \n";
	int ch;
	int x;
	int a = mid(head);
	do
	{
		cout << "1.Insert\n2.Sort\n3.Reverse\n4.Front Back Split\n";
		cout << "Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << "Enter Element: ";
			cin >> x;
			insert(&head, x);
			print(head);
			break;
		case 2: sort(head);
			print(head);
			break;
		case 3: head = reverse(head);
			print(head);
			break;
		case 4: print(head);

			cout << "Mid Element: " << a << "\n";
			cout << "Back List: ";
			print(frontbacksplit(head));
			cout << "Front List: ";
			print(head);
			break;
		default: break;
		}
		cout << "Do u want to continue (1/0) : ";
		cin >> ch;
	} while (ch);
	return 0;
}

void insert(node **head, int x)
{
	node *temp = new node();
	temp->data = x;
	temp->next = *head;
	*head = temp;
}

int mid(node *head)
{
	node *slow = head;
	node *fast = head;
	if (head != NULL)
	{
		while (fast != NULL && fast->next !=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow->data;
	}
}

void print(node *head)
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

node *reverse(node *head)
{
	node *temp, *prev, *current;
	current = head;
	prev = NULL;
	temp = NULL;
	{
	while (current != NULL)
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev;
	return head;
}

node *frontbacksplit(node *head)
{
	node *back;
	node *slow = head;
	node *fast = head;
	if (head == NULL)
	{
		front = head;

	}
	else
	{
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		back = fast->next;
		fast->next = NULL;
	}
	return back;
}
void swap(node *a, node *b)
{
	int c;
	c = a->data;
	a->data = b->data;
	b->data = c;
}

void sort(node *head)
{
	node *temp1;
	node *temp2;
	if (head == NULL)
		return;
	temp1 = head;
	while(temp1 != NULL)
	{
		for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
		{
			if (temp1->data > temp2->data)
			{
				swap(temp1, temp2);
			}
		}
		temp1 = temp1->next;
	}
}

/*
	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		while ((fast->next) != NULL && (fast->next->next) != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		front = head;
		back = slow->next;
		slow->next = NULL;
	}

*/
