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
	int hd;
	node *left, *right;

	node(int key)
	{
		val = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};



int printleafparent(node* root)
{
	if(!root)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;

	int l = printleafparent(root->left);
	int r = printleafparent(root->right);

	if(l==1 || r==1)
	{
		cout<<root->val<<"\n";
	}
	return 0;
}


int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->left = new node(8);
	//top_view(root);
	//bottom_view(root);
	//diagonalPrint(root);
	int x = printleafparent(root);
	return 0;	
}
