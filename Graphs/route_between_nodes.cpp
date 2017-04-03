#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool visited[100];

bool bfs(vector <int> mgr[], int v, int s, int e)
{
	if(s == e)
		return true;
	queue <int> mq;
	mq.push(s);

	while(!mq.empty())
	{
		int curr = mq.front();
		if(curr == e)
		{
			return true;
		}
		q.pop();
		visited[curr] = true;
		int m_s = 
	}

}


int main()
{
	int v,e;
	cout<<"Enter Vertices: ";
	cin>>v;
	cout<<"Enter no of Edges: ";
	cin>>e;
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
	cout<<"BFS:-\n";


	bfs(graph,v, st, ed);
	return 0;
}