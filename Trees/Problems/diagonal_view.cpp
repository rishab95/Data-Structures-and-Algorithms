#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<int,pair<int,int> > mymap;

struct node
{
    int val;    
    //int hd;
    node *left, *right;

    node(int key)
    {
        val = key;
        //hd = INT_MAX;
        left = right = NULL;
    }
};

void diagonal_view(node* root)
{
	queue<node*> q;
	node* last = new node(-1);

	while(root)
	{
		q.push(root);
		root = root->right;
	}
	q.push(last);

	while(q.size() != 1)
	{
		node* temp = q.front();
		q.pop();

		if(temp != last)
		{
			cout<<temp->val<<" ";
			node* t = temp->left;
			while(t)
			{
				q.push(t);
				t = t->right;
			}
		}
		else
		{
			q.push(last);
			cout<<endl;
		}
	}
}

int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->right = new node(8);	
	diagonal_view(root);
	return 0;	
}