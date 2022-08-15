#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int lb, int mid, int ub)
{
	vector<int> ans(ub+1);
	
	int i = lb, j = mid+1, k = lb;
	while(i <= mid && j <= ub)
		if(nums[i]<= nums[j])
			ans[k] = nums[i], i++, k++;
		else
			ans[k] = nums[j], j++,k++;
	
	while(i <= mid)
		ans[k] = nums[i], i++, k++;	
	
	while(j <= ub)
		ans[k] = nums[j], j++, k++;
	
	for(int i = lb; i<= ub; i++)
		nums[i] = ans[i];
}

void mergeSort(vector<int> &nums, int lb, int ub)
{
	if(lb < ub)
	{
		int mid = (lb + ub)/2;
		mergeSort(nums, lb, mid);
		mergeSort(nums, mid+1, ub);
		merge(nums, lb, mid, ub);
	}
}

int main()
{
	vector<int> nums{7, 4, 6, 123, 32, 0, 12};
	mergeSort(nums, 0, nums.size()-1);
	for(auto it: nums)
		cout<< it << " ";
}