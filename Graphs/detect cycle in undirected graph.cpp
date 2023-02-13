#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detect(int src, vector<int> adj[], vector<int> &visited)
{
	queue<pair<int, int>> q;
	q.push({src, -1});
	visited[src] = 1;
	while(!q.empty())
	{
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for(auto adjNode : adj[node])
		{
			if(!visited[adjNode])
			{
				visited[adjNode] = 1;
				q.push({adjNode, node});
			}
			else if(parent != node)
			{
				return true;
			}
		}
	}
	return false;
}

bool checkForCycle(int V, vector<int> adj[])
{
	vector<int> visited(V);
	for(int i = 0; i<V; i++)
	{
		if(!visited[i])
			if(detect(i, adj, visited)) return true;
	}
	return false;
}


void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int Vertex, edge;
	cout<<"Enter the Number of Vertex and Edges:"<<endl;
	cin >> Vertex >> edge;
	vector<int> adj[Vertex];
	for(int i = 0; i<edge; i++)
	{
		int u, v;
		cout<<"Enter u and v:"<<endl;
		cin>> u >> v;
		addEdge(adj, u, v);
	}
	cout<< " Print adjacency list:"<< endl;
	for(auto vec1: adj)
	{
		
		for(auto it: vec1)
			cout<< it << " ";
		cout<<endl;
	}
	cout<<"Cycle Detected:"<<checkForCycle(Vertex, adj);
	
}