//Check T2 is subtree of T1 or not 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x): data(x), left(NULL), right(NULL){}
};

Node* insert(Node* root, int data){
	if(root == NULL)
	{
		root = new Node(data);
		return root;
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;
}

bool is_same(Node* t1, Node* t2)
{
	if(t1 == NULL && t2 == NULL)
		return true;
	else if(t1 == NULL || t2 == NULL)
		return false;

	return (t1->data == t2->data && is_same(t1->left, t2->left) && is_same(t1->right, t2->right));
}

bool is_Subtree(Node* t1, Node* t2)
{
	if(t2 == NULL)
		return true;
	if(t1 == NULL)
		return false;

	if(is_same(t1,t2))
		return true;

	return is_Subtree(t1->left, t2) || 
			is_Subtree(t1->right, t2);
}


int main()
{
	Node *root1 = NULL, *root2 = NULL;
	root1 = insert(root1, 26);
	root1 = insert(root1, 3);
	root1 = insert(root1, 4);
	root1 = insert(root1, 10);
	root1 = insert(root1, 5);
	root1 = insert(root1, 30);
	root1 = insert(root1, 6);
	root1 = insert(root1, 21);
	
	root2 = insert(root2, 10);
	root2 = insert(root2, 6);
	root2 = insert(root2, 4);
	root2 = insert(root2, 30);
	root2 = insert(root2, 21);

	if(is_Subtree(root1, root2))
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}

