#include <iostream>
using namespace std;

class Tree
{
	private:
		struct bst
		{
			bst* left;
			bst* right;
			int data;
		};
		bst* root;
	public:
		Tree()
		{
			root = NULL;
		}
		void Insert(int);
		void inorder(bst*);
		void preorder(bst*);
		void postorder(bst*);
		void printpp();
		int min(bst* );
		void printmin();
		int Treesuccessor(bst*);
		//bool search(int );
		//int height()
		//void remove(int );
};

int Tree::Treesuccessor(bst* x)
{
	bst* y = NULL;
	bst* temp = x;
	if (temp->right != NULL)
	{
		int x = min(temp->right);
		return x;
	}
}


int Tree::min(bst* x)
{
	bst* temp =  new bst();
	temp = x;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

void Tree::printmin()
{
	int m = min(root);
	cout << m << "\n";
}

void Tree::Insert(int val)
{
	bst* t = new bst();
	t->data = val;
	t->left = NULL;
	t->right = NULL;
	bst* parent = new bst();
	parent = NULL;

	if (root == NULL)
	{
		root = t;
	}
	else
	{
		bst* y = new bst();
		y = root;
		while (y)
		{
			parent = y;
			if (t->data > y->data)
			{
				y = y->right;
			}
			else
			{
				y = y->left;
			}
		}
		if (t->data < parent->data)
		{
			parent->left = t;
		}
		else
		{
			parent->right = t;
		}
	}
}

void Tree::postorder(bst* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<< " " << root->data;
	}
	else
		return;
}

void Tree::preorder(bst* root)
{
	if (root != NULL)
	{
		cout << " " << root->data;
		preorder(root->left);
		preorder(root->right);
	}
	else
		return;
}

void Tree::inorder(bst* root)
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

void Tree::printpp()
{
	preorder(root);
}

//bool search()

int main()
{
	int i = 0;
	Tree T;
	int ch, a, x;
	cout << "Binary Search Tree ";
	do
	{
		cout << "\n1. Insertion \n";
		cout << "2. Preoder\n";
		cout << "3. Minimum\n";
		cout << "4. Exit\n";
		cout << "Enter Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << "Enter No: ";
			cin >> a;
			T.Insert(a);
			//i++;
			break;
		case 2: cout << "Pre Order : ";
			T.printpp();
			cout << "\n";
			break;
		case 3: T.printmin();
			break;
		case 4: return 0;
		}
		cout << "\nDo u want to continue (1/0): ";
		cin >> ch;
	} while (ch);
	return 0;
}

/*  Binary Search Tree Implementation
#include <iostream>
using namespace std;

class Tree {
private:
	struct BstNode
	{
		int data;
		BstNode* left;
		BstNode* right;
	};
	BstNode* root;

public:
	Tree()
	{
		root = NULL;
	}
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

	void Insert(BstNode* root, int data)
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
		//return root;
	}
/*
	bool isempty()
	{	
		retu
	}
*/
/*
	bool search(BstNode* root, int data)
	{
		if (root == NULL)
			return false;
		else if (root->data == data)
			return true;
		else if (data <= root->data)
			return search(root->left, data);
		else
			return search(root->right, data);
	}

	void preorder(BstNode* root)
	{
		if (root != NULL)
		{
			cout << root->data << " ";
			preorder(root->left);
			preorder(root->right);
		}
		//else
			//return;
	}

	void inorder(BstNode* root)
	{
		if (root != NULL)
		{
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
		//else
			//return;
	}

	void postorder(BstNode* root)
	{
		if (root != NULL)
		{
			postorder(root->left);
			postorder(root->right);
			cout << root->data << " ";
		}
		//else
			//return;
	}

	int height(BstNode* root)
	{
		if (root == NULL)
			return 0;
		else
		{
			int lefth = 0;
			int righth = 0;
			lefth = height(root->left);

			righth = height(root->right);
			if (lefth > righth)
				return lefth + 1;
			else
				return righth + 1;
		}
	}
};
int main()
{
	//BstNode* root; // Pointer to Root Node
	//root = NULL; // Setting Tree as Empty
	Tree t;
	int ch, a, b;
	cout<<"\n Binary Search Tree"
	do
	{
		cout << "\n 1.Insertion ";
		cout << "\n 2.Print";
		cout << "\n 3.Search";
		cout << "\n 4.Exit";
		cout << "\n Enter Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << "\n Enter the No: ";
			cin >> a;
			t.Insert(root ,a);

			break;
		default
		}
	} while (ch);
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
	
	cout << "\nPre-Order: ";
	preorder(root);
	cout << "\nPost-Order: ";
	postorder(root);
	cout << "\nIn-Order: ";
	inorder(root);
	cout << "\n";
	cout << "Height of Tree: " << height(root)<<"\n";
return 0;
}
*/


