#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node* right;
	Node(int x): data(x), left(NULL), right(NULL){}
};



bool isbst(Node* root){
	static Node* temp = NULL;
	if(root){
		if(!isbst(root->left))
			return false;

		if(temp != NULL && root->data <= temp->data)
			return false;

		temp = root;

		return isbst(root->right);
	}	
	return true;
}

void inorder(Node* root){
	if(root == NULL)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


int main(){
	Node* root; // Pointer to Root Node
	root = NULL; // Setting Tree as Empty
	root = new Node(10);
	root->left = new Node(21);
	root->left->left = new Node(25);
	root->right = new Node(18);
	root->right = new Node(8);
	root->right->right = new Node(14);
	root->right->left = new Node(20);
	if(isbst(root)){
		cout<<"Yes\n";
	}else{
		cout<<"No";
	}
	cout<<"\nIn-Order: ";
	inorder(root);

}