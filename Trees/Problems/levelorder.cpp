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
vector<vector<int> > levelOrder(node* A) {
   queue<node* > q;
   q.push(A);
   q.push(NULL);
   vector<int> level;
   vector<vector<int> > res;
   while(!q.empty())
   {
       node* temp = q.front();
       q.pop();

       if(temp != NULL)
       {       		
            if(temp->left)            
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
           	level.push_back(temp->val);            
           	//cout<<temp->val<<" ";
       }
       else
       {
           res.push_back(level);
           level.clear();
           if(!q.empty())
                q.push(NULL);
       }
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
	vector<vector<int> > ans = levelOrder(root);
	for(int i=0;i<ans.size();i++)
	{
		for(int j = 0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}