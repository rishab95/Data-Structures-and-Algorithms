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
    //int hd;
    node *left, *right;

    node(int key)
    {
        val = key;
        //hd = INT_MAX;
        left = right = NULL;
    }
};

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
    node* root = new node(3);
    root->left = new node(5);
    root->left->right = new node(4);
    root->left->left = new node(1);
    root->left->left->right = new node(9);
    root->right = new node(2);
    root->right->right = new node(7);   
    root->right->left = new node(6);    
    root->right->right->left = new node(8); 
    bottom_view(root);
	return 0;	
}