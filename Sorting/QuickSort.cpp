#include <iostream>
#include <vector>
using namespace std;
int getPivot(vector<int> &nums, int low, int high)
{
	int pivot = nums[low];
	int i = low, j = high;
	while(i < j)
	{
		//looking for smaller element on right
		while(nums[i] <= pivot && i <= high - 1)
			i++;
		//looking for larger element on left
		while(nums[j] > pivot && j >= low+1)
			j--;
		if(i < j) swap(nums[i], nums[j]);
	}
	swap(nums[low], nums[j]);
	return j;
}

void quickSort(vector<int> &nums, int low, int high)
{
	if(low < high)
	{
		int pivot = getPivot(nums, low, high);
		quickSort(nums, low, pivot-1);
		quickSort(nums, pivot+1, high);
	}
}

int main()
{
	//vector<int> nums{8, 89, 3, 53, 70, 0, 4};
	vector<int> nums{80, 7, 3, 14, 90, 2};
	
	int low = 0, high = nums.size()-1;
	quickSort(nums, low, high);
	for(auto it: nums)
		cout<<it << " ";
}