#include <iostream>
#include <vector>
using namespace std;

//Recursion
int minSumPathR(int i, int j, vector<vector<int>> &grid)
{
	if(i == 0 && j == 0) return grid[i][j];
	if(i < 0 || j < 0) return 1e9;
	
	int up = grid[i][j] + minSumPathR(i-1, j, grid);
	int left = grid[i][j] + minSumPathR(i, j-1, grid);
	
	return min(up, left);
}

//Memoization
int minSumPathM(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
	if(i == 0 && j == 0) return grid[i][j];
	if(i < 0 || j < 0) return 1e9;
	
	if(dp[i][j] != -1) return dp[i][j];
	int up = grid[i][j] + minSumPathM(i-1, j, grid, dp);
	int left = grid[i][j] + minSumPathM(i, j-1, grid, dp);
	return min(up, left);
}

//Tabulation
int minSumPathT(int m ,int n, vector<vector<int>> &grid)
{
	vector<vector<int>> dp(m, vector<int>(n, -1));
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(i == 0 && j == 0) dp[i][j] = grid[i][j];
			else
			{
				int up = grid[i][j], left = grid[i][j];
				up += (i > 0) ? dp[i-1][j] : 1e9;
				left += (j > 0) ? dp[i][j-1] : 1e9;
				dp[i][j] = min(up, left);
			}
		}
	}
	return dp[m-1][n-1];
}


//Space Optimaization
int minSumPathS(int m, int n, vector<vector<int>> &grid)
{
	vector<int> prev(n, 0);
	for(int i = 0; i<m; i++)
	{
		vector<int> cur(n, 0);
		for(int j = 0; j<n; j++)
		{
			if(i == 0 && j == 0) cur[j] = grid[i][j];
			else
			{
				int up = grid[i][j], left = grid[i][j];
				up += (i > 0) ? prev[j] : 1e9;
				left += (j > 0) ? cur[j-1] : 1e9;
				cur[j] = min(up, left);
			}
		}
		prev = cur;
	}
	return prev[n-1];
}
int main()
{
	vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	int m = grid.size();
	int n = grid[0].size();
	cout<<"Minimum path sum with Recursion:"<<minSumPathR(m-1, n-1, grid)<<endl;
	
	vector<vector<int>> dp(m, vector<int>(m, -1));
	cout<<"Mininum path sum with Memoization:"<<minSumPathM(m-1, n-1, grid, dp)<<endl;
	
	cout<<"Mininum path sum with Tabulation:"<<minSumPathT(m, n, grid)<<endl;
	
	cout<<"Mininum path sum with Space Optimization:"<<minSumPathS(m, n, grid)<<endl;
}