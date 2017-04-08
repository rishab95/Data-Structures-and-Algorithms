//a bug in the program

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
//bool visited[100];



void graph_color(vector <int> mygraph[], int v){

	int final_color[v];

	final_color[0] = 0;
	for(int i=1;i<v;i++)
		final_color[i] = -1; // set unassigned

	bool avail_color[v];
	for(int i=0;i<v;i++)
		avail_color[i] = false;


	/*for(int i=0;i<mygraph[u-1].size();i++){
		if(visited[mygraph[u-1][i]-1] == false){
			dfs_util(mygraph, mygraph[u-1][i]);
		}
	}*/

	for(int u=1;u<v;u++){
		
		for(int i=0;i<mygraph[u-1].size();i++)
			if(final_color[mygraph[u-1][i]-1] != -1)
				avail_color[final_color[mygraph[u-1][i]-1]] = true;
		
		int cr;
		for(cr=0;cr<v;cr++)
			if(avail_color[cr] == false)
				break;

		final_color[u] = cr; // Assign the color found in prev statement

		for(int i=0;i<mygraph[u-1].size();i++)
			if(final_color[mygraph[u-1][i]-1] != -1)
				avail_color[final_color[mygraph[u-1][i]-1]] = false; // Reset for next iteration
		
	}
	for(int u=0;u<v;u++)
		cout<<"Vertex: "<<u<<"->"<<"Color: "<<final_color[u]<<endl;
}

int main(){
	int v,e;
	cin>>v>>e;
	vector <int> graph[v];
	
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
	graph_color(graph,v);
	return 0;
}
