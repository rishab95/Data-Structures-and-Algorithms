#include <iostream>
#include <algorithm>

using namespace std;

class list{
	private:
		struct node{
			node* next;
			int value;
		};
		node* head;
	public:
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
		void reverse_list(){
			node *current = head, *prev = NULL, *nxt = NULL;
			while(current != NULL){
				nxt =current->next;
				current ->next = prev;
				prev = current;
				current = nxt;
			}			
			head = prev;
		}
		void ret_kth_last(int k){
			node *p = head, *q = head;
			for(int i=0;i<k;i++){
				if(q == NULL)
					return;
				q = q->next;
			}
			while(q != NULL){
				q = q->next;
				p = p->next;
			}			
			head = p;
		}

		//Bug in the code
		void partition_k(int k){
			node *left = NULL, *right = NULL, *current = head, *left_end = NULL;
			node* nxt = current->next;
			//current->next = NULL;
			while(current != NULL){
				if(current->value < k)
				{
					if(left == NULL)
					{
						left = current;
						left->next = NULL;						
						current->next = NULL;
					}					
					else
					{
						left->next = current;
						current->next = NULL;
						left_end = left->next;
					}
				}
				else
				{	
					if(right == NULL)
					{
						right = current;	
						right->next = current;						
						current->next = NULL;
					}
					else
					{
						right->next = current;						
						current->next = NULL;						
					}
					
				}
				current = nxt;
			}		
			//left->next = right;			
			right->next = NULL;
			//head = left;
		}

		
		node* loop_detect()
		{
			node* slow = head;
			node* fast = head;
			int flag = 0;
			while(fast != NULL && fast->next != NULL){
				slow = slow->next;
				fast = fast->next->next;
			}		
			if(slow == fast){
				flag = 1;
				break;
			}
			if(fast == NULL && fast->next == NULL)
				return NULL;
			if(flag == 1){
				slow = head;
				while(slow != fast){
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
			return NULL;
		}		

		bool 
};


int main()
{
	list l;
	int x;
	cout<<"Enter value to add: ";		
	while(true){
		cin>>x;
		if(x == -1)
			break;
		l.addnode(x);
	}
	l.print_list();
	//l.reverse_list();
	//l.print_list();
	int k;
	cout<<"\nEnter k: ";
	cin>>k;
	//l.partition_k(k);
	//l.print_list();
	//l.ret_kth_last(k);
	//l.print_list();
	return 0;
}


