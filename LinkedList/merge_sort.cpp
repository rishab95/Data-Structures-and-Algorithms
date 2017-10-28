#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	int val;
	//int hd;
	node *next;// *right;	
};

void frontbacksplit(node* head, node** front, node** back)
{
	node* slow;
	node* fast;
	if(head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while(fast != NULL)
		{
			fast = fast->next;
			if(fast !=NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}	

node* sortedmerge(node* a, node* b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	node* res = NULL;
	if(a->val <= b->val)
	{
		res = a;
		res->next = sortedmerge(a->next, b);
	}
	else
	{
		res = b;
		res->next = sortedmerge(a, b->next);
	}
	return res;
}


void mergesort(node** headRef)
{
	node* head = *headRef;
	node* a=NULL;
	node* b=NULL;  
	if ((head == NULL) || (head->next == NULL))
		return;
	 
  
	frontbacksplit(head, &a, &b);    
	mergesort(&a);
	mergesort(&b);   
	*headRef = sortedmerge(a, b);
}

void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}

void push(node** head_ref, int new_data)
{
  
	node* new_node = new node();  
	new_node->val  = new_data;  
	new_node->next = (*head_ref);    
 	(*head_ref)    = new_node;
}

int main()
{
	node* a = NULL;    
	push(&a, 15);
	push(&a, 10);
	push(&a, 5); 
	push(&a, 20);
	push(&a, 3);
	push(&a, 2); 
	push(&a, 30); 
	print(a);;
	mergesort(&a);
	print(a);;
	return 0;
}