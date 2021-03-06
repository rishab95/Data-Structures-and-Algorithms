#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
bool visited[100];
stack <int> mstack;

void topsort_util(vector <int> mygraph[], int u){
	visited[u] = true;
	//cout<<u<<" ";
	for(int i=0;i<mygraph[u].size();i++){
		if(visited[mygraph[u][i]] == false){
			topsort_util(mygraph, mygraph[u][i]);
		}
	}
	mstack.push(u);
}

void top_sort(vector <int> mygraph[], int v){
	//stack <int> mstack;	
	for(int i=0;i<v;i++){
		if(visited[i] == false){
			topsort_util(mygraph, i);
		}
	}
	while(!mstack.empty()){
		cout<<mstack.top()<<" ";
		mstack.pop();
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
		cout<<i<<"-> ";
		for(int j=0;j<graph[i].size();j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;		
	}
	cout<<"Topological Sort:-\n";
	top_sort(graph,v);
	return 0;
}
