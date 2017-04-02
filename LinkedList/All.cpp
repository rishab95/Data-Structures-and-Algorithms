#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};
struct Node *head;
void insert_begin(int);
void insert_end(int , int);
void insert_any(int, int);
void insert_sorted()

void print();

int main()
{
	head = NULL; 
	int carryon = 1;
	char ch;
	head = NULL;

	while(carryon == 1)
	{
		//Display menu to the user
		cout<<"\n1. Insert at front\n";
		cout<<"\n2. Insert at end\n";
		cout<<"\n3. Insert at any position\n";
		cout<<"\n4. Display linked list\n";
		cout<<"\nEnter your choice: ";
		cout<<choice;

		switch(choice)
		{
			case '1': insert_begin();
					  break;
			case '2': insert_end();
					  break;
			case '3': insert_any();
					  break;
			case '4': print();
					  break;
		}
		cout<<"Do you want to continue (1/0)";
		cin>>carryon;
	} 
	return 0;
}

void insert_end(int data)
{
	cin>>data;
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;

	Node* temp2 = head;
	while(temp2->next != NULL)
	{
		temp2 = temp2->next;
	}

	temp1->next = temp2->next; // set link field of newly created node to n-1th node
	temp2->next = temp1; // link of n-1th to new node


}

void insert_begin(int x)
{
	int x;
	cin>>x;
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	/*if(head!=NULL)
		temp->next = head; */ 
	head = temp;
}

void insert_any(int data, int n)
{
	Node* temp1 = new Node();
	temp1->data = data; // setting data field to data
	temp1->next = NULL; // link field to null
	// Need to handle special case when at head

	// for all other cases go to the n-1th node
	Node* temp2 = head; // pointing to head
	for(int i=0;i<n-2;i++)
		temp2 = temp2->next;
	temp1->next = temp2->next; // set link field of newly created node to n-1th node
	temp2->next = temp1; // link of n-1th to new node
	

}

void print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<"\n";
		temp = temp->next;
	}
}
 
