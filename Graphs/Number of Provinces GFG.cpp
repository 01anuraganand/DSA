#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &storeDfs)
{
	storeDfs.push_back(node);
	visited[node] = 1;
	for(auto it: adj[node])
	{
		if(!visited[it])
			dfs(it, adj, visited, storeDfs);
	}
}
int numProvinces(vector<int> adj[], int V)
{
	int countProvince = 0;
	vector<int> visited(V+1, 0);
	vector<int> storeDfs;
	for(int i = 1; i<V; i++)
	{
		if(!visited[i])
			{
				countProvince++;	
				dfs(i, adj, visited, storeDfs);
			}
	}
	return countProvince;
}
int main()
{
	int Vertex, Edge;
	cout<<"Enter the number of vertices(vertex start from 1):"<<endl;
	cin>>Vertex;
	cout<<"Enter the number of edges:"<<endl;
	cin>>Edge;
	
	vector<int> adj[Vertex+1];
	for(int i = 0; i<Edge; i++)
	{
		int u, v;
		cin>> u >> v;
		addEdge(adj, u, v);
	}
	
	cout<<"Adjacency Matrix:"<<endl;
	for(auto vec1: adj)
	{
		for(auto it: vec1)
			cout<< it << " ";
		cout<< endl;
	}
	
	cout<<"Number of Province:" << numProvinces(adj, Vertex)<<endl;		
}