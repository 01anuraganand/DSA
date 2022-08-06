#include <iostream>
#include<vector>
using namespace std;


vector<vector<int>> undirectedGraph(int num_Nodes, int num_Edge)
{
	vector<vector<int>> AdjancencyMat(num_Nodes+1, vector<int>(num_Nodes+1, 0));
	for(int i = 0; i<num_Edge; i++)
	{
		int u, v;
		cout<< "Enter u and v:";
		cin>> u >> v;
		AdjancencyMat[u][v] = 1;
		AdjancencyMat[v][u] = 1;
	}
	return AdjancencyMat;
}

vector<vector<int>> directedGraph(int num_Nodes, int num_Edge)
{
	vector<vector<int>> AdjancencyMat1(num_Nodes+1, vector<int> (num_Nodes+1, 0));
	for(int i = 0; i<num_Edge; i++)
	{
		int u, v;
		cout<<"Enter u and v:";
		cin>> u >> v;
		AdjancencyMat1[u][v] = 1;
	}
	return AdjancencyMat1;
}

int main()
{
	int num_Nodes, num_Edge;
	cout<< "Enter Number of Nodes and Edges for undirectedGraph:";
	cin >> num_Nodes >> num_Edge;
	vector<vector<int>> AdjancencyMat = undirectedGraph(num_Nodes, num_Edge);
	for(int i = 0; i<=num_Nodes; i++)
	{	cout<< endl;
		for(int j = 0; j<=num_Nodes; j++)
			cout<< AdjancencyMat[i][j]<< " ";
	}
	
	cout<<endl;
	
	cout<< "Enter Number of Nodes and Edges for directedGraph:";
	cin >> num_Nodes >> num_Edge;
	vector<vector<int>> AdjancencyMat1 = directedGraph(num_Nodes, num_Edge);
	for(int i = 0; i<=num_Nodes; i++)
	{	cout<< endl;
		for(int j = 0; j<=num_Nodes; j++)
			cout<< AdjancencyMat1[i][j]<< " ";
	}
}