#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class ProcessingQueriesInMatrix
{
public:
	// Naive Approach TC: O(m*n*Q)
	int getSumMatrix(vector<vector<int>> &matrix, int row, int col, int rightMostRow, int downMostCol)
	{
		int sum = 0;
		for(int i = row; i<=rightMostRow; i++)
		{
			for(int j = col; j<=downMostCol; j++)
				sum += matrix[i][j];
		}
		return sum;
	}
	void ProcessingQueriesInMatrixNaive(vector<vector<int>> &matrix, vector<pair<pair<int, int>, pair<int, int>>> & queries)
	{
		int n = matrix.size();
		int m = matrix[0].size();
		for(int i = 0; i<queries.size(); i++)
		{
			int topLeftR = queries[i].first.first;
			int topLeftC = queries[i].first.second;

			int bottomRightR = queries[i].second.first;
			int bottomRightC = queries[i].second.second;

			cout<<getSumMatrix(matrix, topLeftR, topLeftC, bottomRightR, bottomRightC)<<endl;
		}
	}

	// Optimal Approach using prefixSum TC : O(m*n + q)
	void ProcessingQueriesInMatrixPrefixSum(vector<vector<int>> &matrix, vector<pair<pair<int, int>, pair<int, int>>> &queries)
	{
		int n = matrix.size();
		int m = matrix[0].size();
		// Computing Prefix Sum row wise
		for(int i = 0; i<n; i++)
		{
			for(int j = 1; j<m; j++)	
				matrix[i][j] += matrix[i][j-1];
		}

		// Computing Prefix Sum on newly created matrix by column wise
		for(int i = 1; i<n; i++)
		{
			for(int j = 0; j<m; j++)
				matrix[i][j] += matrix[i-1][j];
		}


		for(int i = 0; i<queries.size(); i++)
		{
			int topLeftR = queries[i].first.first;
			int topLeftC = queries[i].first.second;

			int bottomRightR = queries[i].second.first;
			int bottomRightC = queries[i].second.second;

			int sum = matrix[bottomRightR][bottomRightC];
			if(topLeftR > 0) sum -= matrix[topLeftR-1][bottomRightC];
			if(topLeftC > 0) sum -= matrix[bottomRightR][topLeftC-1];
			if(topLeftR > 0 && topLeftC > 0) sum += matrix[topLeftR-1][topLeftC-1];
			cout<<sum<<endl;
		}
	}

};
int main()
{
	vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<pair<pair<int, int>, pair<int, int>>> queries{
		{{0, 0}, {2, 2}},
		{{1, 1}, {2, 2}},
		{{1, 0}, {2, 1}},
	};
	ProcessingQueriesInMatrix obj;
	obj.ProcessingQueriesInMatrixNaive(matrix, queries);
	cout<<endl;
	obj.ProcessingQueriesInMatrixPrefixSum(matrix, queries);
}