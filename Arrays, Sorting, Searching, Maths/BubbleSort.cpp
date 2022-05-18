// Bubble Sort 

#include <bits/stdc++.h>
using namespace std;

vector<int> BubbleSort(vector<int> &nums)
{	
	int N = nums.size();
	for (int i = 0; i< N; i++)
		for (int j = 0; j<N-i-1; j++)
		{
			if (nums[j] > nums[j+1])
				swap(nums[j], nums[j+1]);
		}
	return nums;
}

int main()
{
	int N, number;
	vector<int> nums;
	cin>>N;
	for(int i = 0; i<N; i++)
	{	cin>>number;
		nums.push_back(number);
	}
	
	
	nums = BubbleSort(nums);
	for(auto it: nums)
		cout<<it << " ";
}