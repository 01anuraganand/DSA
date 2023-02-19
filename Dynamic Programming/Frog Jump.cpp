#include <iostream>
#include <vector>
using namespace std;

//Memoization
int frogJumpM(int index, vector<int> & heights, vector<int> &dp)
{
	if (index == 0) return 0;
	
	if(dp[index] != -1) return dp[index];
	
	int firstStep = frogJumpM(index-1, heights, dp) + abs(heights[index] - heights[index-1]);
	int secondStep = INT_MAX;
	if(index >1)
		secondStep = frogJumpM(index-2, heights, dp) + abs(heights[index] - heights[index-2]);
	
	return dp[index] = min(firstStep, secondStep);
}

//Tabulation
int frogJumpT(vector<int> &heights)
{
	int n = heights.size();
	vector<int> dp(n, -1);
	dp[0] = 0;
	for(int i= 1; i<n; i++)
	{
		int firstStep = dp[i-1] + abs(heights[i] - heights[i-1]);
		int secondStep = INT_MAX;
		if(i > 1)
			secondStep = dp[i-2] + abs(heights[i] - heights[i-2]);
		dp[i] = min(firstStep, secondStep);
	}
	return dp[n-1];
}

//Space Optimization
int frogJumpS(vector<int> &heights)
{
	int n = heights.size();
	int prev2, prev1 = 0;
	for(int i = 1; i<n; i++)
	{
		int firstStep = prev1 + abs(heights[i] - heights[i-1]);
		int secondStep = INT_MAX;
		if(i > 1)
			secondStep = prev2 + abs(heights[i] - heights[i-2]);
		
		int curr = min(firstStep, secondStep);
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}
int main()
{
	vector<int> heights{30, 10, 60, 10, 60, 50};
	int n = heights.size();
	vector<int> dp(n+1, -1);

	cout<<frogJumpM(n-1, heights, dp);
	
	cout<<endl;
	cout<<frogJumpT(heights);
	
	cout<<endl;
	cout<<frogJumpS(heights);
}