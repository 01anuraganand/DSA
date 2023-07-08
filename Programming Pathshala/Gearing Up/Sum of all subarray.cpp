#include <iostream>
#include <vector>
using namespace std;
class SumOfAllSubarray
{
public:

	// Brute force Approach
	// Brute force approach functions TC: (N*(N-1)/2)*N
	int getSum(vector<int> &nums, int i, int j)
	{
		int sum = 0;
		for(int k = i; k<=j; k++)
			sum += nums[k];
		return sum;
	}
	int SumOfAllSubarrayBruteForce(vector<int> &nums)
	{
		int sum = 0;
		int n = nums.size();
		for(int i = 0; i<n; i++)
		{
			for(int j = i; j<n; j++)
				sum += getSum(nums, i, j);
		}
		return sum;
	}


	// Sum of all subarray using prefixSum TC : O(N*N) SC : O(N)
	int SumOfAllSubarrayPrefixSum(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> prefixSum(n);

		prefixSum[0] = nums[0];
		for(int i = 1; i<n; i++)
			prefixSum[i] += prefixSum[i-1] + nums[i];

		int sum = 0;
		for(int i = 0; i<n; i++)
		{
			for(int j = i; j<n; j++)
			{
				sum += prefixSum[j];
				if(i>0) sum -= prefixSum[i-1];
			}
		}
		return sum;
	}

	// Sum of all subarray with two variable mechanism TC : O(N*N)
	int SumOfAllSubarrayTwoSum(vector<int> &nums)
	{
		int n = nums.size();
		int totalSum = 0;
		int sum = 0;
		for(int i = 0; i<n; i++)
		{
			int sum = 0;
			for(int j = i; j<n; j++)
			{
				sum += nums[j];
				totalSum += sum;
			}
		}
		return totalSum;
	}

	// Sum of all Subarray using combinatorics approach and Reverse Look Up,  TC: O(N)
	int SumOfAllSubarrayCombinatorics(vector<int> &nums)
	{
		int sum = 0;
		int n = nums.size();
		for(int i = 0; i<n; i++)
		{
			sum += (i+1)*(n-i)*nums[i];
		}
		return sum;
	}
};
int main()
{
	vector<int> nums{1, 2, 3, 4};
	SumOfAllSubarray obj;
	cout<<obj.SumOfAllSubarrayBruteForce(nums)<<endl;
	cout<<obj.SumOfAllSubarrayPrefixSum(nums)<<endl;
	cout<<obj.SumOfAllSubarrayTwoSum(nums)<<endl;
	cout<<obj.SumOfAllSubarrayCombinatorics(nums)<<endl;
}