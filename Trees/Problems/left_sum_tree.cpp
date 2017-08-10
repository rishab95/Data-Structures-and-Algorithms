/*
Given a Binary Tree, change the value in each node to sum of all 
the values in the nodes in the left subtree including its own.
*/

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	int val;
	//int hd;
	node *left, *right;

	node(int key)
	{
		val = key;
		//hd = INT_MAX;
		left = right = NULL;
	}
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int update_tree_leftsum(node* root)
{
    if(!root)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->val;

    int left_sum = update_tree_leftsum(root->left);
    int right_sum = update_tree_leftsum(root->right);

    root->val = root->val + left_sum;

    return root->val + right_sum;
}

void inorder(node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->left = new node(8);
    update_tree_leftsum(root);
    inorder(root);
    return 0; 
}