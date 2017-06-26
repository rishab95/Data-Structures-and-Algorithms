#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<int,pair<int,int> > mymap;

struct node
{
	int val;	
	int hd;
	node *left, *right;

	node(int key)
	{
		val = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};



void topviewutil(node* root, mymap& m, int level = 1, int hd = 0)
{
	if(!root)
		return;
	if(m.find(hd) == m.end() || level < m[hd].first)
	{
		m[hd] = make_pair(level, root->val);
	}
	topviewutil(root->left, m, level+1, hd-1);
	topviewutil(root->right, m, level+1, hd+1);
}

void top_view(node *root)
{
	mymap m1;
	topviewutil(root, m1);
	for(mymap :: iterator i=m1.begin();i!=m1.end();i++)
		cout<<(i->second).second<<" ";
	cout<<endl;

}


void bottom_view(node* root)
{
    if(!root)
        return;
    map<int, int> m;
    queue<pair<node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();
        m[temp.second] = (temp.first)->val;
        if((temp.first)->left)
            q.push(make_pair((temp.first)->left, temp.second-1));
        if((temp.first)->right)
            q.push(make_pair((temp.first)->right, temp.second+1));
    }
    map<int,int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        cout<<it->second<<" ";
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
	//top_view(root);
	//bottom_view(root);
	diagonalPrint(root);
	return 0;	
}