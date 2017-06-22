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
		void print_list()
		{
			node* current = head;
			while(current != NULL){
				cout<<current->value<<" ";
				current = current->next;
			}
 			cout<<endl;
		}

		
};

void sortlist(node* head)
{
	//cout<<head->value;
	int c1= 0, c2 = 0, c3 = 0;
	node* curr = head;

	while(curr != NULL)
	{
		if(curr->value == 0)
		{			
			c1++;
			curr = curr->next;
		}
		else if(curr->value == 1)
		{
			c2++;
			curr = curr->next;
			}
		else
		{
			c3++;
			curr = curr->next;
		}
	}
	curr = head;
	while(curr != NULL)
	{
		if(c1 != 0)
		{
			c1--;
//			/cout<<head->value;
			curr->value = 0;
			curr = curr->next;			
		}
		else if(c2 != 0)
		{
			c2--;
			curr->value = 1;
			curr = curr->next;			
		}
		else
		{
			c3--;
			curr->value = 2;
			curr = curr->next;			
		}
	}
	//cout<<head->value;
}


int main()
{
	list l1, l2;
	l1.addnode(1);
	l1.addnode(2);
	l1.addnode(0);
	l1.addnode(1);
	l1.addnode(2);
	l1.addnode(0);	
	l1.print_list();
	sortlist(l1.head);
	l1.print_list();
	return 0;
}
