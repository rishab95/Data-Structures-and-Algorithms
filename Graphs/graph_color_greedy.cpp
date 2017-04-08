#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
bool visited[100];

void dfs_util(vector <int> mygraph[], int u){
	visited[u-1] = true;
	cout<<u<<" ";
	for(int i=0;i<mygraph[u-1].size();i++){
		if(visited[mygraph[u-1][i]-1] == false){
			dfs_util(mygraph, mygraph[u-1][i]);
		}
	}
}

void dfs(vector <int> mygraph[], int v){
	for(int i=0;i<v;i++){
		if(visited[i] == false){
			dfs_util(mygraph, i+1);
		}
	}
}

int main(){
	int v,e;
	cin>>v>>e;
	vector <int> graph[v];
	for(int i=0;i<v;i++)
		visited[i] = false;
	cout<<"Enter Edges: \n";
	int a, b;
	for(int i=0;i<e;i++){		
		cin>>a>>b;
		graph[a-1].push_back(b);
	}
	cout<<"Adjacency List: \n";
	for(int i=0;i<v;i++){
		cout<<i+1<<"-> ";
		for(int j=0;j<graph[i].size();j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;		
	}
	cout<<"DFS:-\n";
	dfs(graph,v);
	return 0;
}
