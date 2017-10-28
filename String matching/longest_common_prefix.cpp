#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#define SIZE 26
using namespace std;

struct trieNode{
	trieNode* child[SIZE];
	bool isLeaf;
};

trieNode* getNode()
{
	trieNode* temp = new trieNode();
	for(int i=0;i<SIZE;i++)
		temp->child[i] =  NULL;		

	temp->isLeaf = false;
	return temp;
}

void insert(trieNode* root, string s)
{
	trieNode* node = root;
	int index;
	for(int i=0;i<s.length();i++)
	{
		index = s[i] - 'a';
		if(!node->child[index])
			node->child[index] = getNode();
		node = node->child[index];
	}	
	node->isLeaf = true;
}

int countChild(trieNode* root, int *index)
{
	int count=0;
	for(int i=0;i<SIZE;i++)
	{
		if(root->child[i] != NULL)
		{
			count++;
			*index = i;
		}
	}
	return count;
}

string prefix(trieNode* root)
{
	string result;
	int index;
	trieNode* crawl = root;
	while(countChild(crawl, &index) == 1 && crawl->isLeaf == false)
	{
		crawl = crawl->child[index];
		result.push_back('a' + index);
	}
	return result;
}

void constructTrie(trieNode* root, string str[], int n)
{
	for(int i=0;i<n;i++)
		insert(root, str[i]);
}

string commonPrefix(string str[], int n)
{
	trieNode* root = getNode();
	constructTrie(root, str, n);

	return prefix(root);
}

int main()
{
	int n;
	cin>>n;
	string str[n];
	for(int i=0;i<n;i++)
	{
		cin>>str[i];	
	}
	string ans = commonPrefix(str, n);
	if(ans.length() != 0)
        cout<<"BAD SET\n";
    else
        cout<<"GOOD SET\n";
    return 0;
}
