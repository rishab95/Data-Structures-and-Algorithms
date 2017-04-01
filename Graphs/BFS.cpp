#include<iostream>
#include<queue>
using namespace std;

void bfs(int V, int source)
{
	int adj[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			adj[i][j] = 0;
		}
	}
	int edges;
	for(int i=0;i<V;i++)
	{
		cout<<"Enter Nodes Adjancent to "<<i<<"\n";
		while(true)
		{
			cin>>edges;
			if(edges == -1)
			{
				break;
			}
			adj[i][edges] = 1;
		}
	}
	queue <int> q;
	int distance[V];
	for(int i=0;i<V;i++)
		distance[V] = 0;
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;
	q.push(source);
	visited[source] = true;
	while(!q.empty())
	{
		source = q.front();
		cout<<source<<" ";
		q.pop();
		for(int i=0;i<V;i++)
		{
			if(adj[source][i] == 1)
			{
				if(visited[i] == false)
				{
					distance[i] = 1 + distance[source];
					q.push(i);
					visited[i] = true;
				}
				
			}
		}
		
	}
}

int main()
{
	int v;
	cout<<"Enter No of Vertices: ";
	cin>>v;
	int s;
	cout<<"\nEnter the source Node: ";
	cin>>s;
	bfs(v, s);
}
