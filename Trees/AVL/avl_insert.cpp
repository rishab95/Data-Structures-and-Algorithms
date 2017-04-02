#include <iostream>
using namespace std;

struct node{
	int val;
	node *left;
	node *right;
	int ht;
};

node* newnode(int val){
    node* n = new node();
    n->val   = val;
    n->left   = NULL;
    n->right  = NULL;
    n->ht = 0;  // new node is initially added at leaf
    return n;
}

int ht(node *N)
{
    if (N == NULL)
        return 0;
    return N->ht;
}

int getBalance(node *N){
    if (N == NULL)
        return 0;
    return ht(N->left) - ht(N->right);
}

int max(int a, int b){
	return (a>b)?a:b;
}

node* rightrotate(node* root){
	node* t = root->left;
	node* b = t->right;

	//Perform rotation
	t->right = root;
	root->left = b;

	root->ht =  max(ht(root->left),ht(root->right))+1;
	t->ht =  max(ht(t->left),ht(t->right))+1;

	//newly formed root of tree;
	return t;

}

node* leftrotate(node* root){
	node* t = root->right;
	node* b = t->left;

	t->left = root;
	root->right = b;

	root->ht =  max(ht(root->left),ht(root->right))+1;
	t->ht =  max(ht(t->left),ht(t->right))+1;

	//newly formed root of tree;
	return t;	
}

node* insert(node* root, int val){
 	if (root == NULL)
        return(newnode(val));
 
    if (val < root->val)
        root->left  = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    else // Equal vals are not allowed in BST
        return root;

    root->ht = 1 + max(ht(root->left), ht(root->right));

    int bf = getBalance(root);
    //ll
    if(bf > 1 && val < root->left->val) {
    	return rightrotate(root);
    }
    //rr
    if(bf < -1 && val > root->right->val){
    	return leftrotate(root);
    }
    //lr
    if(bf > 1 && val > root->left->val){
    	root->left = leftrotate(root);
    	return rightrotate(root);
    }
    //rl
    if(bf < -1 && val < root->right->val){
    	root->right = rightrotate(root);
    	return leftrotate(root);
    }

    return root;
}

void preorder(node* root){
	if(root!=NULL){
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main(){
	//int x, ch;
	node* root = new node();
	root = NULL;
	root = insert(root,15);
	root = insert(root,18);
	root = insert(root,12);
	root = insert(root,13);
	root = insert(root,10);
	root = insert(root,11);
	root = insert(root,9);
	preorder(root);

	return 0;
}

/*
/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;


node* create_node(int val)
{
    node* n = (node*) malloc(sizeof(node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    n->ht = 0;
    return n;
}

int height(node* n)
{
    if (n == NULL) {
        return -1;
    }
    return n->ht;
}

int calculate_height(node* n)
{
    return 1 + max(height(n->left), height(n->right));
}

int weight(node* n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

node* right_rotate(node* root)
{
    node* oldRoot = root;
    root = oldRoot->left;
    oldRoot->left = root->right;
    root->right = oldRoot;

    oldRoot->ht = calculate_height(oldRoot);
    root->ht = calculate_height(root);

    return root;

}

node* left_rotate(node* root)
{
    node* oldRoot = root;
    root = oldRoot->right;
    oldRoot->right = root->left;
    root->left = oldRoot;

    oldRoot->ht = calculate_height(oldRoot);
    root->ht = calculate_height(root);

    return root;
}

node* balance(node* root)
{
    int w = weight(root);

    if (root == NULL || abs(w) <= 1)
        return root;

    if (w > 0) {
        if (weight(root->left) < 0)
            root->left = left_rotate(root->left);
        return right_rotate(root);
    } else {
        if (weight(root->right) > 0)
            root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

node* insert(node* root, int val)
{
    if (val < root->val) {
        if (!root->left)
            root->left = create_node(val); 
        else
            root->left = insert(root->left, val);
    } 
    else if (val > root->val) {
        if (!root->right)
            root->right = create_node(val);
        else 
            root->right = insert(root->right, val);
    }

    root->ht = calculate_height(root);

    return balance(root);
}
*/
