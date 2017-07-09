#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int info;
    node* left;
    node* right;
    node* prevLeft;
};

void getNextRight(node* root)
{
	root = root->nextRight;
	while(root!=NULL)
	{
		if(root->left!= NULL)
			return root->left;
		if(root->right!= NULL)
			return root->right;
		root = root->nextRight;
	}
	return NULL;
}

void connect(node* root)
{
	node* firstatlevel = root;
	while(firstatlevel)
	{
		node* iter = firstatlevel;
		while(iter)
		{
			if(iter->left)
			{
				if(iter->right)
				{
					iter->left->nextRight = iter->right;
					iter->right->nextRight = getNextRight(iter);
				}
				else
				{
					iter->left->nextRight = getNextRight(iter);
				}
			}
			else if(iter->right)
			{
				iter->right->nextRight = getNextRight(iter);
			}

			iter = iter->nextRight;
		}
		if(firstatlevel->left)
		{
			firstatlevel = firstatlevel->left;
		}
		else if(firstatlevel->right)
		{
			firstatlevel = firstatlevel->right;
		}
		else
		{
			firstatlevel = getNextRight(firstatlevel);
		}
	}
}

		
int main() { 
    int t; 
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n+1];
        int i=1;
        while(i<=n){
            cin>>arr[i];
            i++;
        }
        node* root;
        createTree(root, arr, 1, n);
        connectPrev(root); 
        printSol(root); 
        reverseLevelOrderTraverse(root); 
    }
    return 0; 
}
node* createNewNode(int info) {
    node* root = new node();
    root->info = info; 
    root->left = NULL;
    root->right = NULL; 
    return root; 
}
void createTree(node* &root, int arr[], int i, int n) { 
    if(i>n)
        return;
    if(arr[i] != -1){
        root = createNewNode(arr[i]); 
        createTree(root->left, arr, i*2, n); 
        createTree(root->right, arr, i*2 +1, n); 
    } 
    return;
}
void printSol(struct node *root) { 
    struct node* firstAtLevel = root;
    while(firstAtLevel) {
        struct node* iter = firstAtLevel;
        firstAtLevel = NULL; 
        while(iter) {
            if(firstAtLevel == NULL){
                if(iter->right)
                    firstAtLevel = iter->right;
                else if(iter->left) 
                    firstAtLevel = iter->left; 
            } 
            cout<<iter->info; 
            iter = iter->prevLeft; 
        } 
    } 
} 

void reverseLevelOrderTraverse(struct node* root) {
    if(!root) return; 
    queue<struct node*> q; 
    stack<struct node*> s; 
    q.push(root); 
    q.push(NULL); 
    while(!q.empty()) { 
        root = q.front(); 
        q.pop();
        if(root != NULL) {
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
            s.push(root);
        } 
        else 
        {
            while(!s.empty()){ 
                struct node* poped = s.top();
                s.pop(); cout<<poped->info;
            } if(!q.empty()) q.push(NULL);
        } 
    } 
} 
