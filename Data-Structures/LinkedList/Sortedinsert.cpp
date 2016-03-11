#include<iostream>
using namespace std;

struct node{
  int data;
  node* next;
};
node* head = NULL;
void insert(int data)
{
  node* ptr = new node();
  ptr->data = data;
  ptr->next = head;
  head = ptr;
}

void print()
{
  node* temp = head;
  while(temp != NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

void sortedinsert(int data)
{
  node* ptr = new node();
  ptr->data = data;
  node* current;
  if(head == NULL || (head->data) >= (ptr->data))
  {
    ptr->next = head;
    head = ptr;
  }
  else
  {
    current = head;
    while(current->next != NULL && (current->next->data) < ptr->data)
    {
      current = current->next;
    }
    ptr->next = current->next;
    current->next = ptr;
  }
}

int main()
{
  int ch, x;
  sortedinsert(4);
  print();
  cout<<"\n";
  sortedinsert(5); print();
  cout<<"\n";
  sortedinsert(7); print();
  cout<<"\n";
  sortedinsert(8); print();
  cout<<"\n";
  sortedinsert(6); print();
  cout<<"\n";
  return 0;
}
