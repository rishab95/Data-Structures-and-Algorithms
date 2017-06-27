#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Graph{
	private:
		int n;
		vector<vector<int> > graph;
		vector<bool> visit;
		//void dfsaux(int);
	public:
		Graph(int v)
		{
			n = v;
			graph.resize(n);
			visit.resize(n);	
			//memset(visit,false,n);
			fill(visit.begin(), visit.end(), false);
		}
		void addEdge(int s, int d)
		{
			graph[s].push_back(d);
		}
		void bfs(int);
};

void Graph::bfs(int s)
{
	for(int i=0;i<n;i++)
		visit[i] = false;

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
	g.bfs(0);
	return 0;
}
