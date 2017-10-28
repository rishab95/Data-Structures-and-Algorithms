#include<bits/stdc++.h>
using namespace std;
struct node{
	struct node *child[26];
	int isleaf;
};

struct node *getnode()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	for(int i=0;i<26;i++)
		temp->child[i]=NULL;
	temp->isleaf=-1;
}

void add(struct node * root,string s,int k)
{
	struct node *temp;
	temp=root;
	int ind;
	for(int i=0;i<s.size();i++)
	{
		ind=s[i]-'a';
		if(temp->child[ind]==NULL)
		{
			temp->child[ind]=getnode();
			temp->isleaf=k;
		}
		if(temp->isleaf<k)
		temp->isleaf=k;
		temp=temp->child[ind];
	}
	temp->isleaf=0;
}

int ans;
void add1(struct node * root,string s)
{
	ans=-1;
	int ind;
	struct node *temp=root;
	for(int i=0;i<s.size();i++)
	{
		ind=s[i]-'a';
		if(temp->child[ind]==NULL)
		{
			ans=-1;
			break;
		}
		ans=temp->isleaf;
		temp=temp->child[ind];
	}
}


