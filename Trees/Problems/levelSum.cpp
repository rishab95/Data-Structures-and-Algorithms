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
int levelOrderSum(node* A) {
    if(A == NULL)
        return 0;
    int res = A->val;
    queue<node*> q;
    q.push(A);
    
    while(!q.empty())
    {
        int ct = q.size();
        int s = 0;
        while(ct--)
        {
            node* t = q.front();
            q.pop();
            s = s + t->val;

            if(t->left != NULL)
                q.push(t->left);
            if(t->right != NULL)
                q.push(t->right);

        }
        res = max(res, s);
    }
    return res;
}


int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->left = new node(8);
	cout<<levelOrderSum(root)<<endl;
    return 0; 
}