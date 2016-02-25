#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
	BstNode* parent;
};
//BstNode* root; // to store address of Root Node
//root = NULL;
BstNode* Getnewnode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL)
	{
		root = Getnewnode(data);
		return root;
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

BstNode* search(BstNode* root, int data)
{
	if (!(root))
		return NULL;
	else if (root->data == data)
		return root;
	else if (data < root->data)
		return search(root->left, data);
	else
		return search(root->right, data);
}

int minimum(BstNode* x)
{
	BstNode* temp = x;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->data;
}

BstNode* minval(BstNode* x)
{
	while (x->left != NULL)
	{
		x = x->left;
	}
	return x;
}

BstNode* successor(BstNode* x, int val)
{
	BstNode* temp;
	temp = search(x, val);
	if (temp->right != NULL)
	{
		return minval(temp->right);
	}
	BstNode* y = temp->parent;
	while (y != NULL &&  temp == y->right)
	{
		temp = y;
		y = y->parent;
	}
	return y;
}




void preorder(BstNode* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
	else
		return;
}

void inorder(BstNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	else
		return;
}

void postorder(BstNode* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
	else
		return;
}

int main()
{
	BstNode* root; // Pointer to Root Node
	root = NULL; // Setting Tree as Empty
	int ch, a, x;
	BstNode* temp, *scs;
	cout << "Binary Search Tree ";
	do
	{
		cout << "\n1. Insertion \n";
		cout << "2. Preoder\n";
		cout << "3. Minimum\n";
		cout << "4. Search\n";
		cout << "5. Successor\n";
		cout << "6. Exit\n";
		cout << "Enter Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << "Enter No: ";
			cin >> a;
			root = Insert(root, a);
			inorder(root);
			break;
		case 2: cout << "Pre Order : ";
			preorder(root);
			cout << "\n";
			break;
		case 3: x = minimum(root);
			cout << "Min is: " << x<<endl;
			break;
		case 4: cout<<"Enter No to Search:  ";
			int s;
			cin >> s;
			temp = search(root, s);
			if (temp)
			{
				cout << "Element Found: " << temp->data;
			}
			else
			{
				cout << "Not Found!!\n";
			}
			break;
		case 5: int e;
			cout << "Enter Element whose Successor u want: ";
			cin >> e;
			scs = successor(root, e);
			cout << "Successor: " << scs->data<<"\n";
			break;
		case 6: exit;
			break;
		default: break;
		}
		cout << "\nDo u want to continue (1/0): ";
		cin >> ch;
	} while (1);

	return 0;
}
