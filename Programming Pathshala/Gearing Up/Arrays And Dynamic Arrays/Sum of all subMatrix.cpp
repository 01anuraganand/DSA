#include <iostream>
#include <vector>
using namespace std;
class sumOfAllSubMatrix
{
public:

	// Brute Force approach to consider all subarray one by one
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
	int sumOfAllSubMatrixBruteForce(vector<vector<int>> &matrix)
	{
		int sum = 0;
		int n = matrix.size();
		int m = matrix[0].size();
		for(int row = 0; row<n; row++)
		{
			for(int col = 0; col<m; col++)
			{
				for(int rightMostRow = row; rightMostRow < n; rightMostRow++)
				{
					for(int downMostCol = col; downMostCol < m; downMostCol++)
						sum += getSumMatrix(matrix, row, col, rightMostRow, downMostCol);
				}
			}
		}
		return sum;
	}


	// Sum of all sub matrix using combinatorics and reverse lookup
	int sumOfAllSubMatrixCombinatorics(vector<vector<int>> &matrix)
	{
		int sum = 0, n = matrix.size(), m = matrix[0].size();
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<m; j++)
			{
				sum += ((i+1)*(j+1) * (n - i)*(m-j) * matrix[i][j]);
			}
		}
		return sum;
	}

};
int main()
{
	sumOfAllSubMatrix obj;
	vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}};

	cout<<obj.sumOfAllSubMatrixBruteForce(matrix)<<endl;
	cout<<obj.sumOfAllSubMatrixCombinatorics(matrix)<<endl;
}
