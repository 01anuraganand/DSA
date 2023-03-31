#include <iostream>
#include <vector>
using namespace std;

int mod = int(1e9+7);

//Recursion
int mazeObstaclesR(int i, int j, vector<vector<int>> &mat)
{
	if(i >=0 && j >=0 && mat[i][j] == -1) return 0;
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	int up = mazeObstaclesR(i-1, j, mat);
	int left = mazeObstaclesR(i, j-1, mat);
	return (up+left)%mod;
}

//Memoization
int mazeObstaclesM(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
	if(i >= 0 && j >= 0 && mat[i][j] == -1) return 0;
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int up = mazeObstaclesM(i-1, j, mat, dp);
	int left = mazeObstaclesM(i, j-1, mat, dp);
	return dp[i][j] = (up + left)%mod;
}

//Tabulation
int mazeObstaclesT(int m, int n, vector<vector<int>> &mat)
{
	vector<vector<int>> dp(m, vector<int> (n, -1));
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(mat[i][j] == -1) dp[i][j] = 0;
			else if(i == 0 && j == 0)  dp[i][j] = 1;
			else
			{
				int up =0, left = 0;
				if(i > 0) up = dp[i-1][j];
				if(j > 0) left = dp[i][j-1];
				dp[i][j] = (up + left) % mod;
			}
		}
	}
	return dp[n-1][m-1];
}

//Space Optimization
int mazeObstaclesS(int m, int n, vector<vector<int>> &mat)
{
	vector<int> prev(n, -1);
	for(int i = 0; i<m; i++)
	{
		vector<int> cur(n, -1);
		for(int j = 0; j<n; j++)
		{
			if(mat[i][j] == -1) cur[j] = 0;
			else if(i == 0 && j == 0) cur[j] = 1;
			else
			{
				int up = 0, left = 0;
				if(i > 0 ) up = prev[j];
				if(j > 0) left = cur[j-1];
				cur[j] = (up+left) % mod;
			}
		}
		prev = cur;
	}
	return prev[n-1];
}

int main()
{
	vector<vector<int>> mat {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
	int m = mat.size();
	int n = mat[0].size();
	cout<<"Maze Obstacle with Recursion:"<<mazeObstaclesR(m-1, n-1, mat)<<endl;
	
	vector<vector<int>> dp(m, vector<int>(n, -1));
	cout<<"Maze Obstacle with Memoization:"<<mazeObstaclesM(m-1, n-1, mat, dp)<<endl;
	
	cout<<"Maze Obstacle with Tabulation:"<<mazeObstaclesT(m, n, mat)<<endl;
	
	cout<<"Maze Obstacle with Space Optimization:"<<mazeObstaclesS(m, n, mat)<<endl;
	
}