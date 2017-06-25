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
void correct(node* root, node** f, node** m, node** e, node** p)
{
	if(root)
	{
		correct(root->left, f, m, e, p);

		if(*p && (*p)-> val > root->val)
		{
			if(! *f)
			{
				*f = *p;
				*m = root;
			}
			else
				*e = root;
		}
		*p = root;
		correct(root->right, f, m, e, p);
	}
}

vector<int>  recoverbst(node* root)
{
	node *f=NULL, *m=NULL, *e=NULL, *p=NULL;
	correct(root, &f, &m, &e, &p);
	vector<int> res;
	if(f && e)
	{
		res.push_back(f->val);
		res.push_back(e->val);
		cout<<f->val<<" "<<e->val;
		swap((f->val), (e->val));
	}
	else if(f && m)
	{
		res.push_back(f->val);
		res.push_back(m->val);
		cout<<f->val<<" "<<m->val;
		swap((f->val), (m->val));
	}
	return res;
}

int main()
{
	node* root = new node(6);
	root->left = new node(3);
	root->left->left = new node(5);
	root->left->right = new node(2);
	root->right = new node(9);
	root->right->right = new node(12);
	vector<int> ans;
	ans = recoverbst(root);
	cout<<" "<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}
