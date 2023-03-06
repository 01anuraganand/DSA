#include <iostream>
#include <vector>
using namespace std;

//Memoization
long long int houseRobberM(int index, vector<int> & nums, vector<int> &dp)
{
	if(index == 0) return nums[index];
	if(index < 0) return 0;
	int pick = nums[index] + houseRobberM(index - 2, nums, dp);
	int notPick = 0 + houseRobberM(index - 1, nums, dp);
	
	return dp[index] = max(pick, notPick);
}

//Tabulation
long long int houseRobberT(vector<int> &nums)
{
	int n = nums.size();
	vector<int> dp(n , -1);
	dp[0] = nums[0];
	for(int i = 1; i<n; i++)
	{
		int pick = nums[i];
		if(i > 1) pick += dp[i-2];
		int notPick = 0 + dp[i-1];
		dp[i] = max(pick, notPick);
	}
	return dp[n-1];
}

//Space Optimization
long long int houseRobberS(vector<int> & nums)
{
	int n = nums.size();
	vector<int> dp(n, -1);
	int prev2 = 0, prev1 = nums[0];
	for(int i = 1; i<n; i++)
	{
		int pick = nums[i];
		if(i > 1) pick += prev2;
		int notPick = 0 + prev1;
		int curr = max(pick, notPick);
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}


int main()
{
	vector<int> nums{10, 3, 2, 1, 7};
	int n = nums.size();
	vector<int> temp1, temp2;
	for(int i = 0; i<n; i++)
		if(i != 0) temp1.push_back(nums[i]);
	for(int i = 0; i<n; i++)
		if(i != n-1) temp2.push_back(nums[i]);
	
	vector<int> dp(n+1, -1);
	cout<<max(houseRobberM(n-2, temp1, dp), houseRobberM(n-2, temp2, dp))<<endl;
	cout<<max(houseRobberT(temp1), houseRobberT(temp2))<<endl;
	cout<<max(houseRobberS(temp1), houseRobberS(temp2))<<endl;

}