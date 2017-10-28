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

node* reverse_pair(node* head, int k)
{
	node *prev = NULL, *next = NULL, *curr = head;
	int ct=0;
	while(curr != NULL && ct < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		ct++;
	}
	if(next != NULL)
		head->next = reverse_pair(next, k);

	return prev;
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
	node* t = reverse_pair(a, 3);
	//mergesort(&a);
	print(t);
	return 0;
}