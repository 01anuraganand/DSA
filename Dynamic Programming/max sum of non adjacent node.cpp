#include <iostream>
#include <vector>
using namespace std;

//Memoization
int maxNonAdjancentSumM(int index, vector<int> & nums, vector<int> & dp)
{
	if(index == 0) return nums[index];
	if(index < 0) return 0;
	if(dp[index] != -1) return dp[index];
	int pick = nums[index] + maxNonAdjancentSumM(index -2, nums, dp);
	
	int nonPick = 0 + maxNonAdjancentSumM(index -1, nums, dp);
	return dp[index] = max(pick, nonPick);
}

//tabulation
int maxNonAdjancentSumT(vector<int> &nums)
{
	int n = nums.size();
	vector<int> dp(n, -1);
	dp[0] = nums[0];
	for(int i = 1; i<n; i++)
	{
		int pick = nums[i];
		if(i >1) pick += dp[i-2];
		int notPick = 0 + dp[i-1];
		dp[i] = max(pick, notPick);
	}
	return dp[n-1];
}

//Space Optimization
int maxNonAdjancentSumS(vector<int> & nums)
{
	int n = nums.size();
	vector<int> dp(n, -1);
	int prev2 = 0, prev1 = nums[0];
	for(int i = 1; i<n; i++) 
	{
		int pick = nums[i];
		if(i>1) pick += prev2;
		int notPick = 0 + prev1;
		int curr = max(pick, notPick);
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}

int main()
{
	vector<int> nums{2, 1, 4, 9};
	int n = nums.size();
	vector<int> dp(n+1, -1);
	cout<<maxNonAdjancentSumM(n-1, nums, dp)<<endl;
	cout<<maxNonAdjancentSumT(nums)<<endl;
	cout<<maxNonAdjancentSumS(nums)<<endl;
}