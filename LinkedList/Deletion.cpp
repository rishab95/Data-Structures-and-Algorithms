#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	/* data */
};

node* insert(node* head, int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
	head = newnode;
}

int delete_head(node* head)
{
	node* trav ;
	if(head == NULL)
	{
		cout<<"Empty List\n";
		return 0;
	}		
	else
	{
		trav = head;
		head = head->next;
		delete trav;
		return 0;
	}
	return 1; // failure
}

int delete_end(node* head)
{
	node* trav, *var;
	trav = head;
	while(trav->next != NULL)
	{
		var = trav;
		trav = trav->next;
	}
	var->next = NULL;
	delete trav;
	return 0;
}


int delete_any(node* head, int position)
{
	node* trav;
	if(position = 1)
	{
		trav = head;
		head = head->next;
		free(trav);
	}
	else
	{
		node* temp = head, *var;
		for(int i = 1;i < position && temp!= NULL;i++)
		{
			var = temp;                               // reach till the node b4 node to be del
			temp = temp->next;
		}

		if(i >= position && var->next != NULL)
		{
			trav = var->next;
			var->next = var->next->next;
			free(trav);
			return 0;    // success ! :)
		}
		return 1;  // if failed
	}
}
