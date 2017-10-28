#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define SIZE 26
using namespace std;

struct TrieNode{
	TrieNode* child[SIZE];
	bool isChild;
};

TrieNode* getNode()
{
	TrieNode* temp = new TrieNode();
	for(int i=0;i<SIZE;i++)
		temp->child[i] =  NULL;		
	temp->isChild = false;
	return temp;
}

void insert(TrieNode* root, string key)
{
	TrieNode* temp = root;
	for(int i=0;i<key.length();i++)
	{
		int index = key[i] - 'a';
		if(!temp->child[index])
			temp->child[index] = getNode();
		temp = temp->child[index];
	}
	temp->isChild = true;
}

bool search(TrieNode* root, string key)
{
	TrieNode* crawl = root;
	for(int i=0;i<key.length();i++)
	{
		int index = key[i] - 'a';
		if(!crawl->child[index])
			return false;
		crawl = crawl->child[index];
	}
	return (crawl != NULL && crawl->isChild);
}

int main()

{
	string s[] = {"the", "hello", "any", "number", "their"};
	TrieNode* root = getNode();
	int n = sizeof(s)/sizeof(s[0]);
	for(int i=0;i<n;i++)
		insert(root, s[i]);

	search(root, "hello") ? cout<<"Yes\n" : cout<<"No\n";
	search(root, "their") ? cout<<"Yes\n" : cout<<"No\n";
	return 0;
}


