//a bug in the program
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
//bool visited[100];



void graph_color(vector <int> adj[], int V){

	int color[V]; // to store colors
	for(int i=0;i<V;i++)
		color[i] = 0;

	color[0] = 0; // assign ist color to 1st vertex

	bool unavail[V];
	//temorary array to store availability of colors
	//for a color c if unavailable[c] is true means c is assigned to some of its adjacent vertex
	memset(unavail,false,V);	
	//assign colors to remaining vertices
	for(int i=0;i<V;i++)
	{
		//process all adjacent vertices and mark their colors as unavailable
		for(int j=0;j<adj[i].size();j++)
		{
			int z = adj[i][j];
			if(color[z] != -1)
				unavail[color[z]] = true;
		}
		//find 1st unavail color
		int cr;
		for(cr=0;cr<V;cr++)
		{
			if(unavail[cr] == false)
				break;
		}
		color[cr] = i;
		memset(unavail,false,V);
	}
	for(int i=0;i<V;i++)
	{
		cout<<i<<" - "<<"Color->"<<color[i]<<endl;
	}

}

int main(){
	int v,e;
	cout<<"Enter number of vertices and edges\n";
	cin>>v>>e;
	vector <int> graph[v];	
	cout<<"Enter Edges: \n";
	int a, b;
	for(int i=0;i<e;i++){		
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout<<"Adjacency List: \n";
	for(int i=0;i<v;i++){
		cout<<i+1<<"-> ";
		for(int j=0;j<graph[i].size();j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;		
	}
	cout<<"Graph Coloring greedy algorithm:-\n";
	graph_color(graph,v);
	return 0;
}
