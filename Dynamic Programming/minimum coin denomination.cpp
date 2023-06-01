#include <iostream>
#include <vector>
using namespace std;

//Recursion
int minimumCoinR(int index, vector<int> &coins, int target)
{
	if(index == 0)
	{
		if(target % coins[0] == 0) return target/coins[0];
		return 1e9;
	}
	int notPick = minimumCoinR(index-1, coins, target);
	int pick = 1e9;
	if(coins[index] <= target)
		pick = 1 + minimumCoinR(index, coins, target - coins[index]);
	return min(pick, notPick);
}

//Memoization
int minimumCoinM(int index, vector<int> &coins, int target, vector<vector<int>> &dp)
{
	if(index == 0)
	{
		if(target % coins[0] == 0) return target/coins[0];
		return 1e9;
	}
	if(dp[index][target] != -1) return dp[index][target];
	int notPick = minimumCoinM(index-1, coins, target, dp);
	int pick = INT_MAX;
	if(coins[index] <= target)
		pick = 1 + minimumCoinM(index, coins, target-coins[index], dp);
	return dp[index][target] = min(pick, notPick);
}

//Tabulation
int minimumCoinT(vector<int> coins, int target)
{
	int n = coins.size();
	vector<vector<int>> dp(n, vector<int>(target+1));
	for(int t = 0; t<= target; t++)
	{
		if(t % coins[0] == 0) dp[0][t] =  t/coins[0];
		else dp[0][t] = 1e9;
	}

	for(int index = 1; index < n; index++)
	{
		for(int t = 0; t<=target; t++)
		{
			int notPick = 0 + dp[index-1][t];
			int pick = INT_MAX;
			if(coins[index] <= t)
				pick = 1 + dp[index][t - coins[index]];
			dp[index][t] = min(pick, notPick);
		}
	}
	return dp[n-1][target];
}

//Space Optimization
int minimumCoinS(vector<int> coins, int target)
{
	int n = coins.size();
	vector<int> prev(target+1, 0), curr(target+1, 0);
	for(int t = 0; t<= target; t++)
	{
		if(t % coins[0] == 0) prev[t] =  t/coins[0];
		else prev[t] = 1e9;
	}

	for(int index = 1; index < n; index++)
	{
		for(int t = 0; t<=target; t++)
		{
			int notPick = 0 + prev[t];
			int pick = INT_MAX;
			if(coins[index] <= t)
				pick = 1 + curr[t - coins[index]];
			curr[t] = min(pick, notPick);
		}
		prev = curr;
	}
	return prev[target];
}

int main()
{
	vector<int> coins{1, 2, 3};
	int target = 7;
	int n = coins.size();
	cout<<"Minimum Coin using recursion:"<<minimumCoinR(n-1, coins, target)<<endl;

	vector<vector<int>> dp(n, vector<int>(target+1, -1));
	cout<<"Minimum Coin using memoization:"<<minimumCoinM(n-1, coins, target, dp)<<endl;

	cout<<"Minimum Coin using tabulation:"<<minimumCoinT(coins, target)<<endl;

	cout<<"Minimum Coin using space optimization:"<<minimumCoinS(coins, target)<<endl;
}
