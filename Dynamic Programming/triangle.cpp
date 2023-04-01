#include <iostream>
#include <vector>
using namespace std;

//Recursion
int minimumPathSumR(int i, int j, vector<vector<int>> &traingle, int n)
{
	if(i == n-1) return traingle[n-1][j];
	int down = traingle[i][j] + minimumPathSumR(i+1, j, traingle, n);
	int diagonal = traingle[i][j] + minimumPathSumR(i+1, j+1, traingle, n);
	return min(down, diagonal);
}

//Memoization
int minimumPathSumM(int i, int j, vector<vector<int>> &traingle, int n, vector<vector<int>> &dp)
{
	if(i == n-1) return traingle[n-1][j];
	if(dp[i][j] != -1) return dp[i][j];
	int down = traingle[i][j] + minimumPathSumM(i+1, j, traingle, n, dp);
	int diagonal = traingle[i][j] + minimumPathSumM(i+1, j+1, traingle, n, dp);
	return dp[i][j] = min(down, diagonal);
}

//Tabulation
int minimumPathSumT(vector<vector<int>> &traingle, int n)
{
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for(int j = 0; j<n; j++)
		dp[n-1][j] = traingle[n-1][j];
	
	for(int i = n-2; i>=0; i--)
	{
		for(int j = i; j>= 0; j--)
		{
			int down = traingle[i][j] + dp[i+1][j];
			int diagonal = traingle[i][j] + dp[i+1][j+1];
			dp[i][j] = min(down, diagonal);
		}
	}
	return dp[0][0];
}

//Space Optimization
int minimumPathSumS(vector<vector<int>> &traingle, int n)
{
	vector<int> front(n, 0), cur(n, 0);
	for(int j = 0; j<n; j++)
		front[j] = traingle[n-1][j];
	
	for(int i = n-2; i>=0; i--)
	{
		for(int j = i; j>=0; j--)
		{
			int down = traingle[i][j] + front[j];
			int diagonal = traingle[i][j] + front[j+1];
			cur[j] = min(down, diagonal);
		}
		front = cur;
	}
	return front[0];
}

int main()
{
	vector<vector<int>> traingle{{1}, {2, 3}, {4, 5, 0}, {7, 8, 9, 10}};
	int n = traingle.size();
	cout<<"min path sum in traingle using recursion:"<<minimumPathSumR(0, 0, traingle, n)<<endl;
	
	vector<vector<int>> dp(n, vector<int>(n, -1));
	cout<<"min path sum in traingle using memoization:"<<minimumPathSumM(0, 0, traingle, n, dp)<<endl;
	
	cout<<"min path sum in traingle using tabulation:"<<minimumPathSumT(traingle, n)<<endl;
	
	cout<<"min path sum in traingle using space optimization:"<<minimumPathSumS(traingle, n)<<endl;
}