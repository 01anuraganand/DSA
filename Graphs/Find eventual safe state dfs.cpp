#include <iostream>
#include <vector>
using namespace std;
void addEdge(int u, int v, vector<int> adj[])
{
	adj[u].push_back(v);
}
bool detectCycle(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited, vector<int> &check)
{
	visited[node] = 1;
	pathVisited[node] = 1;
	check[node] = 0;
	for(auto it: adj[node])
	{
		if(!visited[it])
		{
			if(detectCycle(it, adj, visited, pathVisited, check) == true)
			{
				check[node] = 0;
				return true;
			}
		}
		// if path previously visited on same path
		else if(pathVisited[it])
		{
			check[node] = 0;
			return true;
		}
	}
	check[node] = 1;
	pathVisited[node] = 0;
	return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
	vector<int> visited(V, 0);
	vector<int> pathVisited(V, 0);
	vector<int> check(V, 0);
	vector<int> safeNodes;
	for(int i = 0; i<V; i++)
	{
		if(!visited[i])
			detectCycle(i, adj, visited, pathVisited, check);
	}
	for(int i = 0; i<V; i++)
		if(check[i] == 1)
			safeNodes.push_back(i);
	return safeNodes;
}
int main()
{
	int V = 7, edge = 7;
	vector<int> adj[V];
	addEdge(0, 1, adj);
	addEdge(0, 2, adj);
	addEdge(1, 3, adj);
	addEdge(1, 2, adj);
	addEdge(2, 5, adj);
	addEdge(3, 0, adj);
	addEdge(4, 5, adj);
	
	cout<<"Adjacency list:"<<endl;
	for(auto vec1: adj)
	{
		cout<<endl;
		for(auto it: vec1)
			cout<< it <<  " ";
	}
	
	vector<int> safe = eventualSafeNodes(V, adj);
	for(auto it: safe)
		cout<< it<<" ";
}