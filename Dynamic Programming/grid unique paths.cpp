#include <iostream>
#include <vector>
using namespace std;

//Recurrence 
int uniquePathsR(int i, int j)
{
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	int up = uniquePathsR(i-1, j);
	int left = uniquePathsR(i, j-1);
	return up + left;
}

//Memoization
int uniquePathsM(int i, int j, vector<vector<int>> &dp)
{
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int up = uniquePathsM(i-1, j, dp);
	int left = uniquePathsM(i, j-1, dp);
	return dp[i][j] = up + left;
}

//Tabulation
int uniquePathsT(int m, int n)
{
	vector<vector<int>> dp(m, vector<int> (n, 0));
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == 0 && j == 0)  dp[i][j] = 1;
			else
			{ 	int up = 0, left = 0;
				if(i>0) up = dp[i-1][j];
				if(j>0) left = dp[i][j-1];
				dp[i][j] = up + left;
			}
			
		}
	}
	return dp[m-1][n-1];
}

//Space Optimization
int uniquePathsS(int m, int n)
{
	vector<int> prev(n, 0);
	for(int i = 0; i<m; i++)
	{
		vector<int> cur(n, 0);
		for(int j = 0; j<n; j++)
		{
			if(i == 0 && j == 0) cur[j] = 1;
			else
			{
				int up = 0, left = 0;
				if(i > 0) up = prev[j];
				if(j > 0) left = cur[j-1];
				cur[j] = up + left;
			}
		}
		prev = cur;
	}
	return prev[n-1];
}
int main()
{
	int m = 3, n = 3;
	cout<<"Unique path with Recursion:"<<uniquePathsR(m-1, n-1)<<endl;
	
	vector<vector<int>> dp(m, vector<int>(n, -1));
	cout<<"Unique path with Memoization:"<<uniquePathsM(m-1, n-1, dp)<<endl;
	
	cout<<"Unique path with Tabulation:"<<uniquePathsT(m, n)<<endl;
	
	cout<<"Unique path with Space Optimization:"<<uniquePathsS(m, n)<<endl;
}