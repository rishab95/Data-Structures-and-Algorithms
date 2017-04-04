#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <iterator>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node* right;
	Node(int x): data(x), left(NULL), right(NULL){}
};

int depth(Node* root){
	if(root == NULL){
		return 0;
	}
	return max(depth(root->left), depth(root->right))+1;
}

bool isbal(Node* root){
	if(root == NULL){
		return true;
	}
	int l = depth(root->left);
	int r = depth(root->right);
	return abs(l-r)<=1 && isbal(root->left) && isbal(root->right);
}


Node* Insert(Node* root, int data){
	if(root == NULL)
	{
		root = new Node(data);
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

void preorder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


int main(){
	Node* root; // Pointer to Root Node
	root = NULL; // Setting Tree as Empty
	root = Insert(root, 10);
	root = Insert(root, 21);
	root = Insert(root, 25);
	root = Insert(root, 18);
	root = Insert(root, 8);
	root = Insert(root, 14);
	root = Insert(root, 20);
	if(isbal(root)){
		cout<<"Balanced\n";
	}else{
		cout<<"Unbalanced";
	}
	cout<<"\nPre-Order: ";
	preorder(root);

}