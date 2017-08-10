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
void printpath(int ans[], int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void pathaux(node* root, int ans[], int len)
{
    if(root == NULL)
        return;

    ans[len] = root->val;
    len++;

    if(root->left == NULL && root->right == NULL)
        printpath(ans, len);

    else
    {
        pathaux(root->left, ans, len);
        pathaux(root->right, ans, len);
    }
}

void rootLeafPath(node* root)
{
    int res[10000];
    pathaux(root, res, 0);
}



int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->left = new node(8);
    rootLeafPath(root);
    return 0; 
}