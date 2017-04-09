#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
//#include <unordered_map>
using namespace std;
int V;

bool is_Safe(vector <int> adj[], int u, int path[], int c)
{
	for(int i=0;i< adj[u].size();i++){
		if(path[adj[u][i]] == c){
			return false;
		}
	}
	return true;
}

bool ham_cycle_visit(vector <int> adj[], int path[], int u)
{
	//base case - if all vertices are covered
	if(u == V){
		return true;
	}
	for(int i=1;i<=V;i++)
	{
		if(is_Safe(adj, i, path, u))
		{
			path[u] = i;
			//recursively construct the path
			if(ham_cycle_visit(adj,path,u+1))
				return true;

			//if adding v doesn't get u a solution, remove it;
			path[u] = -1;
		}
	}
	return false;
}

void ham_cycle(vector <int> adj[])
{
	int path[V];
	memset(path,0,V);
	if(ham_cycle_visit(adj,path,0) == false)
	{
		cout<<"No Solution\n";
	//	return false;
	}
	//Else print the path;
	for(int i=0;i<V;i++)
	{
		cout<<path[i]<<" ";
	}
	cout<<path[0]<<"\n";
	//return true;
}

int main()
{
		int e,m;
	cout<<"Enter number of vertices and edges\n";
	cin>>V>>e;
	vector<int> a[V];
	cout<<"Enter edges\n";
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cout<<"enter max colors\n";
	//cin>>m;
	ham_cycle(a);
	cout<<endl;
}

