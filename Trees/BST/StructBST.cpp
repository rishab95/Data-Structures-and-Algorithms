//  Binary Search Tree Implementation
#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};
//BstNode* root; // to store address of Root Node
//root = NULL;
BstNode* Getnewnode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data  = data;
	newNode->left  = NULL;
	newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if(root == NULL)
	{
		root = Getnewnode(data);
		return root;
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

bool search(BstNode* root, int data)
{
	if(root == NULL)
		return false;
	else if(root->data == data)
		return true;
	else if(data <= root->data)
		return search(root->left, data);
	else
		return search(root->right, data);
}

void preorder(BstNode* root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	else
		return;
}

void inorder(BstNode* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
	else
		return;
}

void postorder(BstNode* root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
	else
		return;
}

int main()
{
	BstNode* root; // Pointer to Root Node
	root = NULL; // Setting Tree as Empty
	root = Insert(root, 10);
	root = Insert(root, 21);
	root = Insert(root, 25);
	root = Insert(root, 18);
	root = Insert(root, 8);
	root = Insert(root, 14);
	root = Insert(root, 20);
	/*int n;
	cout<<"Enter No: ";
	cin>>n;
	if(search(root, n))
		cout<<"YES\n";
	else
		cout<<"NO\n";
		*/
	cout<<"\nPre-Order: ";
	preorder(root);
	cout<<"\nPost-Order: ";
	postorder(root);
	cout<<"\nIn-Order: ";
	inorder(root);
	cout<<"\n";
	return 0;
}



