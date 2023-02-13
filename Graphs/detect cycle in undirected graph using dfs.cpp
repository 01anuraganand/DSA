#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool detectByDFS(int node, int parent, vector<int> adj[], vector<int> &visited)
{
	visited[node] = 1;
	for(auto adjNode: adj[node])
	{
		if(!visited[adjNode])
		{
			if(detectByDFS(adjNode, node, adj, visited)) return true;
		}
		else if(adjNode != parent)
			return true;
	}
	return false;
}

bool checkForCycle(int V, vector<int> adj[])
{
	vector<int> visited(V);
	for(int i = 0; i<V; i++)
	{
		if(!visited[i])
			if(detectByDFS(i, -1, adj, visited)) return true;
	}
	return false;
}
int main()
{
	int Vertex, edge;
	cout<<"Enter the number of vertices(1 based index) and Edges:"<<endl;
	cin>> Vertex >> edge;
	
	//one based indexing
	vector<int> adj[Vertex+1];
	
	for(int j = 0; j<edge; j++)
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

	
	cout<<"\ndetected Cycle:"<<checkForCycle(Vertex, adj)<<endl;
	
}