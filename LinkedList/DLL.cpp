#include<iostream>
using namespace std;

struct node{
  int data;
  node* next;
  node* prev;
};

void insert(node* head, int data)
{
  node* temp = new node();
  temp->next = head;
  temp->prev = NULL;

  if(head != NULL)
  {
    head->prev = temp;
  }
  head = temp;
}

void print(node* head)
{
  node* last;
  cout<<"In Forward: ";
  while(head != NULL)
  {
    cout<<head->data<<" ";
    last = head;
    head = head->next;
  }
  cout<<"In Backward: ";
  while(last != NULL)
  {
    cout<<last->data<<" ";
    last = last->prev;
  }
}

int main()
{
  node* head = NULL;
  int n;
  cin>> n;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    insert(head, x);
  }
  print(head);
  return 0;
}
