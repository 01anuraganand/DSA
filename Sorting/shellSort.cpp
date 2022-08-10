#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int> &nums)
{
	int i, j, h, key; // h represent gap
	
	for( h = nums.size()/2; h>0; h /= 2)
	{
		for(i = h; i < nums.size(); i++)
		{
			key = nums[i];
			j = i;
			while(nums[j-h]>key && j >= h)
			{
				nums[j] = nums[j-h];
				j -= h;
			}
			nums[j]  = key;
		}
	}
}

int main()
{
	vector<int> nums{12, 34, 54, 2, 3};
	shellSort(nums);
	for(auto it: nums)
		cout<< it << " ";
}