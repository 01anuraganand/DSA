#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &nums)
{
	int i, j, key;
	for(i = 1; i<nums.size(); i++)
	{
		key = nums[i];
		j = i;
		while(nums[j-1]>key && j>=1)
			{
				nums[j] = nums[j-1];
				j--;
			}
		nums[j] = key;
	}
}


int main()
{
	vector<int> nums{8, 89, 3, 53, 70, 0, 4};
	insertionSort(nums);
	for(auto it: nums)
		cout<< it << " ";
}