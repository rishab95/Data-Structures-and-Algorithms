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

void getverticalorder(node* root, map<int,vector<int> > &m, int hd)
{
	if(root == NULL)
		return;
	m[hd].push_back(root->val);
	getverticalorder(root->left, m, hd-1);
	getverticalorder(root->right, m, hd+1);
}

vector<vector<int > > printverticalorder(node* root)
{

	map<int,vector<int> > mp;
	int hd = 0;
	getverticalorder(root, mp, hd);
	vector<vector<int> > res;
	map <int,vector<int> > :: iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{	
		res.push_back(it->second);
		/*for(int i=0;i<it->second[i];i++)
		{
			cout<<"Level: "<<it->first<<" Value: "<<it->second[i]<<" ";
		}*/		
		cout<<endl;
	}
}


int main()
{
	node* root = new node(10);
	root->left = new node(5);
	root->left->left = new node(2);
	root->left->right = new node(20);
	root->right = new node(18);
	root->right->left = new node(8);
	vector<vector<int> > v;
	v = printverticalorder(root);
	int m = v.size();
	for(int i=0;i<m;++)
	{
		for(int j=0;j<v[0].size();i++)
		{
			cout<<"Value: "<<v[i][j<<" ";
		}
	}
	return 0;
}



/*
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > result;
    // Base case
    if (!A) return result;
    // Create a map of horizontalDistance, ListOfTreeNodes(at that horizontalDistance)
    map <int,vector<int> > m;

    // Create queue to do level order traversal.
    // Every item of queue contains node and horizontal distance.
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(A, 0)); // root's horizontalDistance is zero

    while(!q.empty()) {
        // get the queue front
        pair<TreeNode*,int> front = q.front();
        q.pop();
        int currentHorizontalDistance = front.second;
        TreeNode* currentTreeNode = front.first;

        // insert current node to hash map
        m[currentHorizontalDistance].push_back(currentTreeNode -> val);

        if (currentTreeNode -> left != NULL) {
             q.push(make_pair(currentTreeNode -> left, currentHorizontalDistance - 1));
        }
        if (currentTreeNode -> right != NULL) {
            q.push(make_pair(currentTreeNode -> right, currentHorizontalDistance + 1));
        }
    }
     // Traverse the map and print nodes at every horigontal distance
    for (map<int,vector<int> > :: iterator it = m.begin(); it != m.end(); it++) {
        result.push_back(it -> second);
    }
    return result;
}
*/