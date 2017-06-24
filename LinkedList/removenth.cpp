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

node* partition(node* head, int x)
{
	node *s = head, *f = head;
	while(x)
	{
		f = f->next;
		x--;
	}
	f=f->next;

	while(f != NULL)
	{
		f = f->next;
		s = s->next;
	}
	s->next = s->next->next;
	return head;
}

int main()
{
	list l1, l2;
	l1.addnode(30);
	l1.addnode(1);
	l1.addnode(0);
	l1.addnode(2);
	l1.addnode(10);
	l1.addnode(22);
	l1.addnode(12);
	l1.print_list();
	int x = 3;
	l2.head = partition(l1.head, x);
	
	l2.print_list();
	
	return 0;
}
