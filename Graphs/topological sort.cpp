#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(int u, int v, vector<int> adj[])
{
	adj[u].push_back(v);
}

void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
{
	visited[node] = 1;
	for(auto it: adj[node])
	{
		if(!visited[it])
			dfs(it, adj, visited, st);
	}
	st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
	vector<int> visited(V, 0);
	stack<int> st;
	vector<int> ans;
	for(int i = 0; i<V; i++)
	{
		if(!visited[i])
			dfs(i, adj, visited, st);
	}
	
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}

int main()
{
	int V = 6, edge = 6;
	vector<int> adj[V];
	addEdge(2, 3, adj);
	addEdge(3, 1, adj);
	addEdge(4, 0, adj);
	addEdge(4, 0, adj);
	addEdge(4, 1, adj);
	addEdge(5, 0, adj);
	
	for(auto vec1: adj)
	{
		for(auto it : vec1)
			cout<< it << " ";
		cout<<endl;
	}
	
	vector<int> ans = topoSort(V, adj);
	cout<<"Topological sort:"<<endl;
	for(auto it: ans)
		cout<< it << " ";
}
