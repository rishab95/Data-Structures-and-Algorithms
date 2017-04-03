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

void preorder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node* min_bst_util(vector <int> marr, int low, int high){
	if(low > high){
		return NULL;
	}
	int mid = (low + high) / 2;
	Node *node = new Node(marr[mid]);
	node->left = min_bst_util(marr, low, mid-1);
	node->right = min_bst_util(marr, mid+1, high);
	return node;
}

Node* min_bst(vector <int> arr){
	if(arr.size() == 0)
		return NULL;
	return min_bst_util(arr, 0, ((int)arr.size()) - 1);
}

int main(){
	int n;
	cout<<"Enter array size: ";
	cin>>n;
	vector <int> arr(n);
	//iterator i;	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	Node* root = min_bst(arr);
	cout<<"Preorder : \n";
	preorder(root);
	return 0;
}
