#include <iostream>
#include <vector>
using namespace std;

//Recursion
bool minSubsetSumDifferenceR(int index, vector<int> &nums, int target)
{
	if(target == 0) return true;
	if(index == 0 ) return nums[0] == target;

	bool notPick = minSubsetSumDifferenceR(index-1, nums, target);
	bool pick = false;
	if(nums[index] <= target)
		pick = minSubsetSumDifferenceR(index-1, nums, target-nums[index]);
	return notPick | pick;
}

//Memoization
bool minSubsetSumDifferenceM(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
{
	if(target == 0) return true;
	if(index == 0) return nums[0] == target;
	if(dp[index][target] != -1) return dp[index][target];
	
	bool notPick = minSubsetSumDifferenceM(index - 1, nums, target, dp);
	bool pick = false;
	if(nums[index] <= target)
		pick = minSubsetSumDifferenceM(index -1, nums, target - nums[index], dp);

	return dp[index][target] = pick | notPick;
}

//Tabulation
bool minSubsetSumDifferenceT(vector<int> &nums, int target)
{
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int> (target +1));

	for(int index = 0; index < n; index++)
		dp[index][0] = true;
	if(nums[0] <= target)
		dp[0][nums[0]] = true;
	for(int index = 1; index < n; index++)
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
	int mn = 1e9;
	int totalSum = target;
	for(int subset1 = 0; subset1<= totalSum/2; subset1++)
	{
		if(dp[n-1][subset1] == true)
			mn = min(mn, abs((totalSum-subset1) - subset1));
	}
	cout<<"MIN:"<<mn<<endl;
	return dp[n-1][target];
}

//Space Optimization
bool minSubsetSumDifferenceS(vector<int> &nums, int target)
{
	int n = nums.size();
	vector<bool> prev(target+1, false), curr(target+1, false);
	prev[0] = true;

	if(nums[0] <= target)
		prev[nums[0]] = true;

	for(int index = 1; index < n; index++)
	{
		curr[0] = true;
		for(int k = 1; k <= target; k++)
		{
			bool notPick = prev[k];
			bool pick = false;
			if(nums[0] <= k)
				pick = prev[k-nums[index]];
			curr[k] = pick | notPick;
		}
		prev = curr;
	}
	int mn = 1e9;
	int totalSum = target;
	for(int subset1 = 0; subset1<= totalSum/2; subset1++)
	{
		if(prev[subset1] == true)
			mn = min(mn, abs((totalSum-subset1) - subset1));
	}
	cout<<"MIN:"<<mn<<endl;
	return prev[target];
}

int main()
{
	vector<int> nums{1, 2, 3, 4};
	int totalSum = 0;
	for(auto it : nums) totalSum += it;
	int n = nums.size();
	int target = totalSum;
	cout<<"partition a set into two subset with min absoulte sum difference by recursion:"<<minSubsetSumDifferenceR(n-1, nums, target)<<endl;

	vector<vector<int>> dp(n, vector<int> (target +1, -1));
	cout<<"partition a set into two subset with min absoulte sum difference by memoization:"<<minSubsetSumDifferenceM(n-1, nums, target, dp)<<endl;

	cout<<"partition a set into two subset with min absoulte sum difference by tabulation:"<<minSubsetSumDifferenceT(nums, target)<<endl;

	cout<<"partition a set into two subset with min absoulte sum difference by space optimization:"<<minSubsetSumDifferenceS(nums, target)<<endl;

	
}