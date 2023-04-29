#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void countingSort(vector<int> & nums, int div)
{
	int n = nums.size();
	
	vector<int> ans(n, 0), count(10, 0);
	
	for(int i = 0; i<n; i++)
		count[(nums[i]/div)%10]++;
	
	
	for(int i = 1; i<10; i++)
		count[i] += count[i-1];
	
	for(int i = n - 1; i>=0; i--)
	{
		ans[count[(nums[i]/div)%10] - 1] = nums[i];
		count[(nums[i]/div)%10]--;
	}
	
	for(int i = 0; i<n; i++)
		nums[i] = ans[i];
	
}

void radixSort(vector<int> & nums)
{
	int maxNumber = (*max_element(nums.begin(), nums.end()));
	for(int div = 1; maxNumber/div > 0; div *=10)
	{
		countingSort(nums, div);
	}
}

int main()
{
	vector<int> nums{88, 889, 3, 53, 70, 0, 4};
	radixSort(nums);
	cout<<endl;
	for(auto it: nums)
		cout<< it << " ";
}