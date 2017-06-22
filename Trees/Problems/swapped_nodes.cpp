#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Treenode
{
	int val;
	//int hd;
	Treenode *left, *right;

	Treenode(int key)
	{
		val = key;
		//hd = INT_MAX;
		left = right = NULL;
	}
};

void checkrec(Treenode* root, Treenode** low, Treenode** mid, Treenode** high, Treenode** prev)
{
	if(root)
	{
		//check for correct i left;
		checkrec(root->left, low, mid, high, prev);

		if(*prev && root->val < (*prev)->val)
		{
			if(!*low)
			{
				*low = *prev;
				*mid = root;
			}
			else			
				*high = root;
		}
		
		*prev = root;
		checkrec(root->right, low, mid, high, prev);
	}
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void check_swapped(Treenode* root)
{
	Treenode *low, *mid, *high, *prev;
	low = prev = mid = high = NULL;

	checkrec(root, &low, &mid, &high, &prev);
	// when the nodes are not adjacent;
	if(low && high)
	{
		swap(&(low->val), &(high->val));
	}
	if(low && mid)
	{
		swap(&(low->val), &(mid->val));	
	}

}

void inorder(Treenode* root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int height(Treenode* A)
{
	if(A == NULL)
		return 0;
	
	else
	{
		int lh = height(A->left);
		int rh = height(A->right);

		if(lh > rh)
			return (lh+1);
		else
			return (rh+1);
	}
}

void printlevelutil(Treenode* A, int level)
{
	if(level == 0)
		return;
	if(level == 1)
		cout<<A->val<<" ";
	else if(level > 1)
	{
		printlevelutil(A->left, level - 1);
		//printlevelutil(A->right, level - 1);
	}
}


void printlevel(Treenode* root)
{
	int h = height(root);
	for(int i=1;i<=h;i++)
	{
		printlevelutil(root, i);
	}
}


int main()
{
	Treenode* root = new Treenode(10);
	root->left = new Treenode(5);
	root->left->left = new Treenode(2);
	root->left->right = new Treenode(20);
	root->right = new Treenode(18);
	root->right->left = new Treenode(8);
	inorder(root);
	//check_swapped(root);
	cout<<endl;
	//inorder(root);
	cout<<"\nlevel: ";
	printlevel(root);

	return 0;
}

