#include <iostream>
#include <vector>
using namespace std;

//Recursion
bool canPartitionR(int index, vector<int> &nums, int target)
{
	if(target == 0) return true;
	if(index == 0) return nums[0] == target;
	
	bool notPick = canPartitionR(index-1, nums, target);
	
	bool pick = false;
	if(nums[index] <= target)
		pick = canPartitionR(index-1, nums, target - nums[index]);
	return pick or notPick;
}

//Memoization
bool canPartitionM(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
{
	if(target == 0) return true;
	if(index == 0) return nums[0] == target;
	
	if(dp[index][target] != -1) return dp[index][target];
	
	bool notPick = canPartitionM(index-1, nums, target, dp);
	bool pick = false;
	if(nums[index] <= target)
		pick = canPartitionM(index-1, nums, target - nums[index], dp);
	return dp[index][target] = pick or notPick;
}

//Tabulation
bool canPartitionT(int n, vector<int> &nums, int target)
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
bool canPartitionS(int n, vector<int> &nums, int target)
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
	vector<int> nums{2, 3, 3, 3, 4, 5};
	int n = nums.size();
	int totalSum = 0;
	for(auto n: nums)
		totalSum += n;
	
	int targetSum = totalSum/2;
	
	cout<<"partition equal subset sum using recursion:"<<canPartitionR(n-1, nums, targetSum)<<endl;
	
	vector<vector<int>> dp(n, vector<int>(totalSum+1, -1));
	cout<<"partition equal subset sum using memoization:"<<canPartitionM(n-1, nums, targetSum, dp)<<endl;

	cout<<"partition equal subset sum using tabulation:"<<canPartitionT(n, nums, targetSum)<<endl;
	
	cout<<"partition equal subset sum using space optimization:"<<canPartitionS(n, nums, targetSum)<<endl;

}