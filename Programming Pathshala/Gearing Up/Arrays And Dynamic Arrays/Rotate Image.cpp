// Given matrix of N*N dimensioal rotate the matrix by 90 degree in clockwise direction
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin>>matrix[i][j];

	for(int i = 0; i<n; i++)
		reverse(matrix[i].begin(), matrix[i].end());

	for(int i = 0; i<n; i++)
	{
		for(int j=0; j<n-i; j++)
		{
			swap(matrix[i][j], matrix[n-1-j][n-1-i]);
		}
	}

	for(auto vec1: matrix)
	{
		for(auto it: vec1)
			cout<<it<<" ";
		cout<<endl;
	}

}