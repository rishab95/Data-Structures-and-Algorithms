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
	node* tail = head;
	node* curr = head;
	while(curr != NULL)
	{
		node* nxt = curr->next;
		if((curr->value) <= x)
		{
			curr->next = head;
			head = curr;
		}
		else
		{
			tail->next = curr;
			tail = curr;
		}
		curr = nxt;
	}
	tail->next = NULL;
	return head;
}

node* evenodd(node* head)
{
	node* iter = head;
	node* tail = head;
	node* prev = NULL;

	node* new_tail;
	//When all odd b4 even take them to end;
	//while((iter->value)%2==0 && iter!=NULL){

	//}
}

int main()
{
	list l1, l2;
	l1.addnode(30);
	l1.addnode(12);
	l1.addnode(0);
	l1.addnode(3);
	l1.addnode(11);
	l1.addnode(21);
	l1.addnode(9);
	l1.addnode(90);
	l1.print_list();
	int x = 3;
	l2.head = partition(l1.head, 18);
	l2.print_list();
	
	return 0;
}
