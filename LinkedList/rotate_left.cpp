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

node* rotate(node* head, int k)
{
	if(head == NULL || k == 0)
		return head;

	node* iter = head;
	node* split = NULL;
	while(iter->next != NULL)
	{
		if(--k == 0)
		{
			split = iter;			
		}
		iter = iter->next;
	}	
}

int main()
{
	list l1, l2;
	l1.addnode(1);
	l1.addnode(3);
	l1.addnode(5);
	l1.addnode(2);
	l1.addnode(4);
	l1.addnode(6);
	l1.print_list();
	l2.head = rotate(l1.head, 3);
	l2.print_list();
	return 0;
	
}
