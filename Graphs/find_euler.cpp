#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
bool visited[100];

void dfs_util(vector <int> mygraph[], int u){
	visited[u] = true;	
	for(int i=0;i<mygraph[u].size();i++){
		if(visited[mygraph[u][i]] == false){
			dfs_util(mygraph, mygraph[u][i]);
		}
	}
}

bool is_connected(vector <int> mygraph[], int v){

	int i;
	for(i=0;i<v;i++){
		if(mygraph[i].size()!=0){
			break;
		}
	}

	if(i == v) // no edges in graph;
		return true;

	dfs_util(mygraph, i);

	// check all unvisited are vsited;
	for(i=0;i<v;i++){
		if(visited[i] == false && mygraph[i].size() > 0){
			return false;			
		}
	}
	return true;
}

int euler(vector <int> mygraph[], int v){
	if(is_connected(mygraph, v) == false){
		return 0;
	}
	int odd_deg = 0;
	for(int i=0;i<v;i++){
		if(mygraph[i].size()%2 != 0)
			odd_deg++;
	}
	if(odd_deg > 2)
		return 0;

	return (odd_deg) ? 1: 2;	
}

int main(){
	int v,e;
	cout<<"Enter number of vertices and edges\n";
	cin>>v>>e;
	vector <int> graph[v];
	for(int i=0;i<v;i++)
		visited[i] = false;
	cout<<"Enter Edges: \n";
	int a, b;
	for(int i=0;i<e;i++){		
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	/*cout<<"Adjacency List: \n";
	for(int i=0;i<v;i++){
		cout<<i+1<<"-> ";
		for(int j=0;j<graph[i].size();j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;		
	}*/

	int r = euler(graph, v);
	if(r == 0)
		cout<<"No\n";
	else if(r == 1)
		cout<<"Path\n";
	else
		cout<<"Cycle\n";
	return 0;
}