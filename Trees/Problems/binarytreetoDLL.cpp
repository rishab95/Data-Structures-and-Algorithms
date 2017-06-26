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

node* binarytodll(node *root)
{
	if(root == NULL)
		return root;

	if(root->left != NULL)
	{
		node* left = binarytodll(root->left);

		while(left->right != NULL)
			left = left->right;

		left->right = root;

		root->left = left;		
	}

	if(root->right != NULL)
	{
		node* right = binarytodll(root->right);

		while(right->left != NULL)
			right = right->left;

		right->left = root;
		root->right = right;
	}
	return root;
}

node* binaryaux(node* root)
{
	if(root == NULL)
		return NULL;

	root = binarytodll(root);

	while(root->left != NULL)
		root = root->left;

	return root;
}

void print(node* curr)
{
	while(curr != NULL)
	{
		cout<<curr->val<<" ";
		curr = curr->right;
	}
	cout<<endl;
}


int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->right = new node(8);
	node* head = binaryaux(root);
	print(head);
	return 0;
}