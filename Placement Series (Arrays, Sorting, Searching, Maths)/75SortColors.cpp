/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
*/

#include <bits/stdc++.h>
using namespace std;

//T->O(nlogn), S-> O(1)
vector<int> Sort(vector<int> &nums)
{
	sort(nums.begin(),nums.end());
	return nums;
}

// T-> O(N), S-> O(1)
vector<int> SortDutchNationalFlagAlgorithm(vector<int> &nums)
{
	int low = 0, mid = 0, high = nums.size() -1;
	
	while (mid <= high)
	{
		if (nums[mid] == 0)
		{
			swap(nums[low++], nums[mid++]);
			
		}
		
		else if (nums[mid] == 1)
		{
			mid++; 
		}
		
		else if (nums[mid] == 2)
		{
			swap(nums[mid], nums[high--]);
			
		}
	}
	return nums;
}

int main()
{
	int N, number;
	vector<int> nums;
	cin>>N;
	for(int i = 0; i<N; i++)
	{	
		cin>>number;
		nums.push_back(number);
	}
	
	//nums = Sort(nums);
	nums = SortDutchNationalFlagAlgorithm(nums);
	for (auto it: nums)
	{
		cout<<it;
	}
	
	
}