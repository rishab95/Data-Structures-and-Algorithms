#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;


//remove edge u->v
void remEdge(vector <int> adj[], int u, int v){
	for(int i=0;i<adj[u].size();i++){
		if(adj[u][i] == v){
			adj[u][i] = -1;
			break;
		}
	}
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i] == u){
			adj[v][i] = -1;
			break;
		}
	}
}

int dfs_count(vector <int> adj[], int u, bool visited[]){
	visited[u] = true;
	int count = 1;
	for(int i=0;i<adj[u].size();i++){
		int temp = adj[u][i];
		if(temp != -1 && visited[i] == false){
			count+=dfs_count(adj, temp, visited);
		}
	}
	return count;
}

bool is_Edge_Valid(vector <int> adj[], int u, int v, int V){
	// 1) if v is only adjacent vertex of u
	int count = 0;
	for(int i=0;i<adj[u].size();i++){
		if(adj[u][i] != -1){
			count++;
		}
	}
	if(count == 1)
		return true;

	// 2) if there are multiple adjacent nodes,then u-v is not bridge
	/* to check if u-v is bridge*/
	// 2(a) count no. of vertices reachable from u
	bool visited[V];
	memset(visited, false, V);
	int count1 = dfs_count(adj, u, visited);
	// 2(b) remove u-v and count nodes reachable from u after this	
	remEdge(adj, u, v);
	memset(visited, false, V);
	int count2 = dfs_count(adj, u, visited);

	adj[u].push_back(v);
	adj[v].push_back(u);

	return (count1 > count2) ? false : true;
}

void print_Euler_path(vector <int> adj[], int u, int V){
	for(int i =0;i<adj[u].size();i++){

		int v = adj[u][i];
		if(v != -1 && is_Edge_Valid(adj, u, v, V)){
			cout<<u<<"->"<<v<<" ";
			remEdge(adj,u,v);
			print_Euler_path(adj,v,V);
		}
	}
}

void print_tour(vector <int> adj[], int V){
	int u = 0;
	for(int i=0;i<V;i++){
		if(adj[i].size() & 1){
			u = i;
			break;
		}
	}
	print_Euler_path(adj, u, V);
}

int main(){
	int v,e;
	cout<<"Enter number of vertices and edges\n";
	cin>>v>>e;
	vector<int> a[v];
	cout<<"Enter edges\n";
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	/* starting vertex is 0 for euler circuit
	for euler path start with odd-degree vertex
	*/

	print_tour(a,v);
	return 0;
}
