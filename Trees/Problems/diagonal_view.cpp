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

//Do level order traversal in diagoal form;

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
	node* root = new node(3);
	root->left = new node(5);
	root->left->right = new node(4);
	root->left->left = new node(1);
	root->left->left->right = new node(9);
	root->right = new node(2);
	root->right->right = new node(7);	
	root->right->left = new node(6);	
	root->right->right->left = new node(8);	
	diagonal_view(root);
	return 0;	
}