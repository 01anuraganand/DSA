#include <iostream>
#include <vector>
using namespace std;

//Recursion
bool subsetSumToKR(int index, int target, vector<int> &nums)
{
	if(target == 0) return true;
	if(index == 0) return (nums[0] == target);
	bool notPick = subsetSumToKR(index-1, target, nums);
	bool pick = false;
	if(nums[index] <= target)
		pick = subsetSumToKR(index-1, target-nums[index], nums);
	return pick | notPick;
}

//Memoization
bool subsetSumToKM(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
{
	if(target == 0) return true;
	if(index == 0) return (nums[0] == target);
	if(dp[index][target] != -1) return dp[index][target];
	
	bool notPick = subsetSumToKM(index-1, target, nums, dp);
	bool pick = false;
	if(nums[index] <= target)
		pick = subsetSumToKM(index-1, target-nums[index], nums, dp);
	
	return dp[index][target] = pick | notPick;
}

//Tabulation
bool subsetSumToKT(int n, vector<int> &nums, int target)
{
	vector<vector<bool>> dp(n, vector<bool>(target+1, false));
	for(int i = 0; i<n; i++)
		dp[i][0] = true;
	
	if(nums[0] <= target)
		dp[0][nums[0]] = true;
	for(int index = 1; index<n; index++)
	{
		for(int k = 1; k <= target; k++)
		{
			bool notPick = dp[index-1][k];
			bool pick = false;
			if(nums[index] <= k)
				pick = dp[index-1][k-nums[index]];
			dp[index][k] = pick | notPick;
		}
	}
	return dp[n-1][target];
}

//Space Optimization
bool subsetSumToKS(int n, vector<int> &nums, int target)
{
	vector<bool> prev(target+1, false), cur(target+1, false);
	prev[0] = true;
	if(nums[0] <= target)
		prev[nums[0]] = true;
	
	for(int index = 1; index < n; index++)
	{
		cur[0] = true;
		for(int k = 1; k <= target; k++)
		{
			bool notPick = prev[k];
			bool pick = false;
			if(nums[index] <= k)
				pick = prev[k-nums[index]];
			cur[k] = pick | notPick;
		}
		prev = cur;
	}
	return prev[target];
}

int main()
{
	vector<int> nums{1, 2, 3, 4};
	int n = nums.size();
	int target = 4;
	cout<<"subset sum equals to target using recursion:"<<subsetSumToKR(n-1, target, nums)<<endl;
	
	
	vector<vector<int>> dp(n, vector<int>(target+1, -1));
	cout<<"subset sum equals to target using memoization:"<<subsetSumToKM(n-1, target, nums, dp);
	
	cout<<"subset sum equals to target using tabulation:"<<subsetSumToKT(n, nums, target)<<endl;
	
	cout<<"subset sum equals to target using space optimization:"<<subsetSumToKS(n, nums, target)<<endl;
}