#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool dfs(int node, int col,vector<int> adj[], vector<int> & color)
{
	color[node] = col;
	for(auto adjNode: adj[node])
	{
		if(color[adjNode] == -1)
		{
			if(dfs(adjNode, !col, adj, color) == false) return false;
		}
		else if(color[adjNode] == col)
			return false;
	}
	return true;
}


bool isBipartite(int Vertex, vector<int> adj[])
{
	vector<int> color(Vertex, -1);
	for(int i = 0; i<Vertex; i++)
	{
		if(color[i] == -1)
			if(dfs(i, 0,adj, color) == false) return false;
	}
	return true;
}

int main()
{
	int Vertex, Edge;
	cout<<"Enter the number of Vertex and Edges:"<<endl;
	cin>>Vertex >> Edge;
	
	vector<int> adj[Vertex];
	for(int i = 0; i<Edge; i++)
	{
		int u, v;
		cout<<"Enter the u and v:"<<endl;
		cin>>u >> v;
		addEdge(adj, u, v);
	}
	for (auto vec1: adj)
	{
		for(auto it: vec1)
			cout<< it << " ";
		cout<<endl;
	}
	
	cout<<"Is Bipartite:"<<isBipartite(Vertex, adj);
}