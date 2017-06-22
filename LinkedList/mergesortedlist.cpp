#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	node* next;
	int value;
};

class list{		
	
	public:
		node* head;
		list(){

			head = NULL;
		}

		void addnode(int x){
			node* new_node = new node;
			node* current = head;
			node* temp;
			new_node->next = NULL;
			new_node->value = x;

			if(head == NULL){
				head = new_node;				
				current = head;
			}			
			else{
				while(current!= NULL){
					temp=current;
					current = current->next;
				}
				temp->next = new_node;
			}
		}

		void print_list(){
			node* current = head;
			while(current != NULL){
				cout<<current->value<<" ";
				current = current->next;
			}
			cout<<endl;
		}

};

node* mergelist(node* A, node* B)
{
	node *tail = NULL, *head = NULL;
	node *currA = A, *currB = B;

	if(A->value < B->value)
	{
		head = A;		
		currA = A->next;
	}
	else
	{
		head = B;
		currB = B->next;
	}
	tail = head;
	while(currA && currB)
	{
		if(currA->value < currB->value)
		{
			tail->next = currA;
			tail = currA;
			currA = currA->next;		
		}
		else
		{
			tail->next = currB;
			tail = currB;
			currB = currB->next;		
		}
	}
	if(currA)
		tail->next = currA;
	else
		tail->next = currB;

	return head;
}


int main()
{
	list l1, l2;
	l1.addnode(1);
	l1.addnode(3);
	l1.addnode(5);
	l2.addnode(2);
	l2.addnode(4);
	l2.addnode(6);
	l1.print_list();
	l2.print_list();

	list l3;
	l3.head = mergelist(l1.head, l2.head);
	//list l3;
	l3.print_list();
	return 0;
}




