/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number
*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicateTortoiseHare(vector<int> &nums)
	{
		int slow = nums[0];
		int fast = nums[0];
		do
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while(slow != fast);
		
		fast = nums[0];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
	
int findDuplicateHashMap(vector<int> &nums)
{
	while(nums[0] != nums[nums[0]])
		swap(nums[0], nums[nums[0]]);
	return nums[0];
}

int main()
{	
	int n, N;
	vector<int> nums;
	cin>> N;
	for (int i = 0; i< N; i++)
	{
		
		cin>>n;
		nums.push_back(n);
	}
	
	for (auto it : nums)
	{
		cout<<it;
	}
	
	//int duplicate = findDuplicateTortoiseHare(nums);
	
	int duplicate = findDuplicateHashMap(nums);
	
	cout<<"\nDuplicate found is:" << duplicate;
	
}