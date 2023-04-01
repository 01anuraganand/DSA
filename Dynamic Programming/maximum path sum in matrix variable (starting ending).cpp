#include <iostream>
#include <vector>
using namespace std;

//Recursion
int getMaxPathSumR(int i, int j, vector<vector<int>> &matrix)
{
	if(j < 0 || j > matrix[0].size()) return -1e9;
	if(i == 0) return matrix[0][j];
	
	int up = matrix[i][j] + getMaxPathSumR(i-1, j, matrix);
	int leftD = matrix[i][j] + getMaxPathSumR(i-1, j-1, matrix);
	int rightD = matrix[i][j] + getMaxPathSumR(i-1, j+1, matrix);
	return max(up, max(leftD, rightD));
}

//Memoization
int getMaxPathSumM(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
	if(j < 0 || j >= matrix[0].size()) return -1e9;
	if(i == 0) return matrix[i][j];
	if(dp[i][j] != -1) return dp[i][j];
	int up = matrix[i][j] + getMaxPathSumM(i-1, j, matrix, dp);
	int leftD = matrix[i][j] + getMaxPathSumM(i-1, j-1, matrix, dp);
	int rightD = matrix[i][j] + getMaxPathSumM(i-1, j+1, matrix, dp);
	return dp[i][j] = max(up, max(leftD, rightD));
}

//Tabulation
int getMaxPathSumT(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>> dp(n, vector<int> (m, 0));
	
	for(int j = 0; j<m; j++)
		dp[0][j] = matrix[0][j];
	
	for(int i = 1; i<n; i++)
	{
		for(int j = 0; j<m; j++)	
		{
			int up = matrix[i][j] + dp[i-1][j];
			int leftD = matrix[i][j];
			int rightD = matrix[i][j];
			
			leftD += (j-1 >=0) ?  dp[i-1][j-1] : -1e9;
			rightD += (j+1 < m) ? dp[i-1][j+1]: -1e9;
			dp[i][j] = max(up, max(leftD, rightD));
		}
	}
	int mx = -1e9;
	for(int j = 0; j<m; j++)
		mx = max(mx, dp[n-1][j]);
	return mx;
}

//Space Optimization
int getMaxPathSumS(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	
	vector<int> prev(m,0), cur(m, 0);
	for(int j = 0; j<m; j++)
		prev[j] = matrix[0][j];
	for(int i = 1; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			int up = matrix[i][j] + prev[j];
			int leftD = matrix[i][j];
			int rightD = matrix[i][j];
			leftD += (j-1 >= 0) ? prev[j-1] : -1e9;
			rightD += (j+1 < m) ? prev[j+1] : -1e9;
			cur[j] = max(up, max(leftD, rightD));
		}
		prev = cur;
	}
	
	int mx = -1e9;
	for(int j = 0; j<m; j++)
		mx = max(mx, prev[j]);
	return mx;
}

int main()
{
	vector<vector<int>> matrix{
		{1, 2, 10, 4},
		{100, 3, 2, 1},
		{1, 1, 20, 2},
		{1, 2, 2, 1}
	};
	int n = matrix.size();
	int m = matrix[0].size();
	
	cout<<"max path sum with Recursion:";
	int mx = -1e9;
	for(int j = 0; j<m; j++)
		mx = max(mx, getMaxPathSumR(n-1, j, matrix));
	cout<<mx<<endl;
	
	cout<<"max path sum with Memoization:";
	mx = -1e9;
	vector<vector<int>> dp(n, vector<int> (m, -1));
	for(int j = 0; j<m; j++)
		mx = max(mx, getMaxPathSumM(n-1, j, matrix, dp));
	cout<<mx<<endl;
	
	cout<<"max path sum with Tabulation:";
	cout<<getMaxPathSumT(matrix)<<endl;
	
	cout<<"max path sum with Space Optimization:";
	cout<<getMaxPathSumS(matrix)<<endl;	
	
}