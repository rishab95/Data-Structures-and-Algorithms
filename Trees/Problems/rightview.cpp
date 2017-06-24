#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

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

void rightviewaux(node* root, int level, int *maxlevel)
{
	if(root == NULL)
		return;

	if(*maxlevel < level)
	{
		*maxlevel = level;
		cout<<root->val<<" ";
	}

	rightviewaux(root->right, level+1 , maxlevel);
	rightviewaux(root->left, level+1, maxlevel);
}

void rightview(node* root)
{
	int maxlevel = 0;
	rightviewaux(root, 1, &maxlevel);
}

int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->left = new node(8);
	rightview(root);
	return 0;
}