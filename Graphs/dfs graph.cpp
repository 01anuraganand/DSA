#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &storeDfs)
{
	storeDfs.push_back(node);
	visited[node] = 1;
	for(auto it: adj[node])
	{
		if (!visited[it])
			dfs(it, visited, adj, storeDfs);
	}
}

vector<int> dfsGraph(int Vertex, vector<int> adj[])
{
	vector<int> storeDfs;
	vector<int> visited(Vertex+1, 0);
	for(int i = 1; i< Vertex; i++)
	{
		if(!visited[i])
			dfs(i, visited, adj, storeDfs);
	}
	return storeDfs;
}


int main()
{
	int Vertex = 8;
	vector<int> adj[Vertex];
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 5);
	addEdge(adj, 2, 6);
	addEdge(adj, 4, 7);
	cout<< "adjacency list of graph:";
	for(auto vec1: adj)
	{	
		cout<<endl;
		for(auto it: vec1)
			cout<< it;
	}
	cout<<"\nDFS Traversal of Graph: "<<endl;
	vector<int> dfs = dfsGraph(Vertex, adj);
	for(auto it: dfs)
	{
		cout<< it << " ";
	}
}