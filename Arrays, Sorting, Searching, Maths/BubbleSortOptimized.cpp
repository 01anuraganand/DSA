// Bubble Sort Optimzed

#include <bits/stdc++.h>
using namespace std;

vector<int> BubbleSortOptimzed(vector<int> &nums)
{	
	int N = nums.size();
	bool flag;
	for (int i = 0; i<N; i++)
	{	
		flag = false; //Set to false, if array is already sorted, if condition run and breaks;
		for (int j = 0; j<N-i-1; j++)
		{
			if (nums[j] > nums[j+1])
			{
				swap(nums[j], nums[j+1]);
				flag = true;
			}
		}
		
		if (!flag)
		{
			break;
		}
	}
	
	return nums;
}

int main()
{
	int N, number;
	vector<int> nums;
	cin>>N;
	for (int i = 0; i<N; i++)
	{
		cin>>number;
		nums.push_back(number);
	}
	
	nums = BubbleSortOptimzed(nums);
	for(auto it: nums)
		cout<<it <<" ";
}