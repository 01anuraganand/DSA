#include <iostream>
#include <vector>
using namespace std;

void undirectedGraph(int num_Nodes, int num_Edge)
{
	vector<int> AdjancencyList[num_Nodes+1];
	for(int i = 0; i< num_Edge; i++)
	{
		cout<<" Enter u and v:";
		int u, v;
		cin>> u >> v;
		AdjancencyList[u].push_back(v);
		AdjancencyList[v].push_back(u);
	}
	for(auto vec1: AdjancencyList)
	{
		cout<<endl;
		for(auto it : vec1)
			cout<< it << " ";
	}
}

void directedGraph(int num_Nodes, int num_Edge)
{
	vector<int> AdjancencyList1[num_Nodes+1];
	for(int i = 0; i< num_Edge; i++)
	{
		cout<<" Enter u and v:";
		int u, v;
		cin>> u >> v;
		AdjancencyList1[u].push_back(v);
	}
	for(auto vec1: AdjancencyList1)
	{
		cout<<endl;
		for(auto it : vec1)
			cout<< it << " ";
	}
}
int main()
{
	int num_Nodes, num_Edge;
	cout<< "Enter Number of Nodes and Edges for undirectedGraph:";
	cin >> num_Nodes >> num_Edge;
	undirectedGraph(num_Nodes, num_Edge);
	
	cout<< "Enter Number of Nodes and Edges for directedGraph:";
	cin >> num_Nodes >> num_Edge;
	directedGraph(num_Nodes, num_Edge);
	
	
	
}