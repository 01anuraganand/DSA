#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addEdge(int u, int v, vector<int> adj[])
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool bipartiteBFS(int src, vector<int> adj[], vector<int> &color)
{
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		
		for(auto adjNode: adj[node])
		{
			if(color[adjNode] == -1)
			{
				color[adjNode] = !color[node];
				q.push(adjNode);
			}
			else if(color[adjNode] == color[node])
				return false;
		}
	}
	return true;
}

bool isBipartite(vector<int> adj[], int Vertex)
{
	vector<int> color(Vertex, -1);
	for(int i = 0; i<Vertex; i++)
	{
		if(color[i] == -1)
			if(bipartiteBFS(i, adj, color) == false)
				return false;
	}
	return true;
}
int main()
{
	int Vertex, Edge;
	cout<<"Enter the number of vertices and Edges:"	<<endl;
	cin>> Vertex >> Edge;
	vector<int> adj[Vertex];
	for(int i = 0; i<Edge; i++)
	{
		int u, v;
		cout<<"Enter the u and v:"<<endl;
		cin>> u>> v;
		addEdge(u, v, adj);
	}
	
	for(auto vec1: adj)
	{
		for(auto it: vec1)
			cout<<it << " ";
		cout<<endl;
	}
	
	cout<<"Given graph is Bipartite:"<<isBipartite(adj, Vertex);
}