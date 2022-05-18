// Selection Sort 

#include <bits/stdc++.h>
using namespace std;

vector<int> SelectionSort(vector<int> &nums)
{	
	int N = nums.size(),minindex;
	
	for (int i = 0; i<N; i++)
	{	
		minindex = i;
		for (int j = i+1; j<N; j++)
		{
			if (nums[minindex] > nums[j])
				minindex = j;
		}
		swap(nums[minindex], nums[i]);
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
	
	
	nums = SelectionSort(nums);
	for(auto it: nums)
		cout<<it << " ";
}