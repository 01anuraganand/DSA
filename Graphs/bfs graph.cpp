#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

vector<int> bfsGraph(int Vertex, vector<int> adj[])
{
	vector<int> bfs;
	vector<int> visited(Vertex, 0);
	for(int i = 0; i< Vertex; i++)
	{
		if(!visited[i])
		{
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				bfs.push_back(node);
				for(auto it: adj[node])
				{
					if(!visited[it])
					{
						q.push(it);
						visited[it] = 1;
					}
				}
			}
		}
		
	}
	return bfs;
	
}

int main()
{
	int Vertex = 5;
	vector<int> adj[Vertex];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 0, 3);
	addEdge(adj, 2, 4);
	cout<< "adjacency list of graph:"<<endl;
	for(auto vec1: adj)
	{	
		cout<<endl;
		for(auto it: vec1)
			cout<< it;
	}
	cout<<"\nBFS of Graph Traversal: "<<endl;
	vector<int> bfs = bfsGraph(Vertex, adj);
	for(auto it: bfs)
	{
		cout<< it << " ";
	}
}