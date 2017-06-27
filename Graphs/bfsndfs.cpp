#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Graph{
	private:
		int n;
		vector<vector<int> > graph;
		vector<bool> visit;		
		void recdfsaux(int);
		void dfsaux(int);
	public:
		Graph(int v)
		{
			n = v;
			graph.resize(n);
			visit.resize(n);			
		}
		void addEdge(int s, int d)
		{
			graph[s].push_back(d);
		}
		void bfs(int);
		void recdfs(int);
		void dfs(int);
};

void Graph::recdfsaux(int u)
{
	visit[u] = true;
	cout<<u<<" ";
	for(int i=0;i<graph[u].size();i++)
	{
		int x = graph[u][i];
		if(visit[x] == false)
		{
			recdfsaux(x);
		}
	}
}

void Graph::recdfs(int s)
{
	fill(visit.begin(), visit.end(), false);
	for(int i=0;i<n;i++)
	{
		if(visit[i] == false)
		{
			recdfsaux(i);
		}
	}
}

void Graph::bfs(int s)
{
	fill(visit.begin(), visit.end(), false);
	queue<int> q;
	
	q.push(s);
	visit[s] = true;
	//cout<<s<<" ";
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		cout<<t<<" ";
		

		for(int i=0;i<graph[t].size();i++)
		{
			int x = graph[t][i];
			if(visit[x] == false)
			{
				visit[x] = true;
				q.push(x);
				//cout<<x<<" ";
			}
		}		
	}
}

void Graph::dfsaux(int u)
{
	stack<int> s;
	s.push(u);
	//visit[u] = true;
	//cout<<u<<" ";
	while(!s.empty())
	{
		int v = s.top();
		s.pop();
		if(visit[v] == true)
			continue;
		visit[v] = true;
		cout<<v<<" ";
		for(int i=0;i<graph[u].size();i++)
		{
			int x = graph[u][i];
			if(visit[x] == false)
			{
				s.push(x);
			}
		}
	}
	
}

void Graph::dfs(int s)
{
	for(int i=0;i<n;i++)
		visit[i] = false;

	for(int i=0;i<n;i++)
	{
		if(visit[i] == false)
		{
			dfsaux(i);
		}
	}
}


int main()
{
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,5);
	g.addEdge(4,6);
	g.addEdge(4,7);	
	cout<<"BFS: ";
	g.bfs(0);
	cout<<endl<<"Recursive DFS: ";
	g.recdfs(1);
	cout<<endl<<"Iterative DFS: ";
	g.dfs(1);
	return 0;	
}
