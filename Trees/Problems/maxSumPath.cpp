#include <iostream>
#include <map>
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

int sumAux(node* root, int &ans)
{
	if(root ==  NULL)
		return 0;
	int left = sumAux(root->left, ans);
	int right = sumAux(root->right, ans);

	int max_temp = max(max(left,right) + root->val, root->val);

	int all_max = max(max_temp, left + right + root->val);  // sum when no ancestors there present in sum path.

	ans = max(ans, all_max); // Will store max result

	return max_temp;
}

int maxSum(node* root)
{
	int ans = INT_MIN;
	sumAux(root, ans);
	return ans;
}

int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->left = new node(8);
	//root->right->left->right = new node(38);
	cout<<maxSum(root)<<" ";
	return 0;
}