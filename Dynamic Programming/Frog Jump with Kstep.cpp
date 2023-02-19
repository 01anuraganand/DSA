#include <iostream>
#include <vector>
using namespace std;

//Memoization
int frogJumpKStepM(int index, vector<int> & heights, int k, vector<int> &dp)
{
	if(index == 0) return 0;
	if(dp[index] != -1) return dp[index];
	int minJump = INT_MAX;
	for(int jump = 1; jump<= k; jump++)
	{
		if(index - jump >=0)
		{
			int JumpStep = frogJumpKStepM(index - jump, heights, k, dp) + abs(heights[index] - heights[index-jump]);
			minJump = min(minJump, JumpStep);
			dp[index] = minJump;
		}
	}
	return dp[index];	
}

//tabulation
int frogJumpKStepT(vector<int> & heights, int k)
{
	int n = heights.size();
	vector<int> dp(n, -1);
	dp[0] = 0;
	for(int i = 0; i<n; i++)
	{
		int minJump = INT_MAX;
		for(int jump = 1; jump<=k; jump++)
		{
			if(i - jump >= 0)
			{
				int JumpStep = dp[i - jump] + abs(heights[i] - heights[i - jump]);
				minJump = min(minJump, JumpStep);
				dp[i] = minJump;	
			}
		}
	}
	return dp[n-1];	
}

int main()
{
	vector<int> heights{30, 10, 60, 10, 60, 50};
	int n = heights.size();
	vector<int> dp(n+1, -1);
	int k = 5;
	cout<<frogJumpKStepM(n-1, heights, k, dp);
	cout<<endl;
	cout<<frogJumpKStepT(heights, k);
}