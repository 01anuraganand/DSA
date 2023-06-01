#include <iostream>
#include <vector>
using namespace std;

//Recursion
int knapsackR(int index, vector<int> &weight, vector<int> &value, int cap)
{
	if(index == 0)
	{
		if(weight[index] <= cap) return value[index];
		else return 0;
	}

	int notPick = 0 + knapsackR(index -1 , weight, value, cap);
	int pick = INT_MIN;
	if(weight[index] <= cap)
		pick = value[index] + knapsackR(index-1, weight, value, cap - weight[index]);

	return max(pick, notPick);
}

// Memoization
int knapsackM(int index, vector<int> &weight, vector<int> &value, int cap, vector<vector<int>> &dp)
{
	if(index == 0)
	{
		if(weight[index] <= cap) return value[index];
		else return 0;
	}
	if(dp[index][cap] != -1) return dp[index][cap];
	int notPick = 0 + knapsackM(index-1, weight, value, cap, dp);
	int pick = INT_MIN;
	if(weight[index] <= cap)
		pick = value[index] + knapsackM(index-1, weight, value, cap - weight[index], dp);
	return dp[index][cap] = max(pick, notPick);
}

//Tabulation
int knapsackT(vector<int> weight, vector<int> value, int cap)
{
	int n = weight.size();
	vector<vector<int>> dp(n, vector<int>(cap+1, 0));
	for(int wt = weight[0]; wt <= cap ; wt++)
		dp[0][wt] = value[0];
	for(int index = 1; index < n; index++)
	{
		for(int wt = 0; wt <= cap; wt++ )
		{
			int notPick = 0 + dp[index-1][wt];
			int pick = INT_MIN;
			if(weight[index] <= wt)
				pick = value[index] + dp[index-1][wt-weight[index]];
			dp[index][wt] = max(pick, notPick);
		}
	}
	return dp[n-1][cap];
}

//Space Optimization1
int knapsackS1(vector<int> weight, vector<int> value, int cap)
{
	int n = weight.size();
	vector<int> prev(cap+1, 0), curr(cap+1, 0);
	for(int wt = weight[0]; wt <= cap; wt++)
		prev[wt] = value[0];
	for(int index = 1; index<n; index++)
	{
		for(int wt = 0; wt <= cap; wt++)
		{
			int notPick = 0 + prev[wt];
			int pick = INT_MIN;
			if(weight[index] <= wt)
				pick = value[index] + prev[wt-weight[index]];
			curr[wt] = max(pick , notPick);
		}
		prev = curr;
	}
	return prev[cap];
}



//Space Optimization2
int knapsackS2(vector<int> weight, vector<int> value, int cap)
{
	int n = weight.size();
	vector<int> prev(cap+1, 0);
	for(int wt = weight[0]; wt <= cap; wt++)
		prev[wt] = value[0];
	for(int index = 1; index<n; index++)
	{
		for(int wt = cap; wt >=0; wt--)
		{
			int notPick = 0 + prev[wt];
			int pick = INT_MIN;
			if(weight[index] <= wt)
				pick = value[index] + prev[wt-weight[index]];
			prev[wt] = max(pick , notPick);
		}
	}
	return prev[cap];
}
int main()
{
	vector<int> weight{4, 4, 5};
	vector<int> value{30, 40, 60};
	int n = weight.size();
	int cap = 8;
	cout<<"01 knapsackR:"<<knapsackR(n-1, weight, value, cap)<<endl;

	vector<vector<int>> dp(n, vector<int> (cap+1, -1));
	
	cout<<"01 knapsackM:"<<knapsackM(n-1, weight, value, cap, dp)<<endl;

	cout<<"01 knapsackT:"<<knapsackT(weight, value, cap)<<endl;

	cout<<"01 knapsackS1:"<<knapsackS1(weight, value, cap)<<endl;

	cout<<"01 knapsackS2:"<<knapsackS2(weight, value, cap)<<endl;
}