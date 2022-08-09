#include <iostream>
#include <vector>
using namespace std;

// TC(O^2) in all case
void selectionSort(vector<int> &nums)
{
	int i, j, min;
	for(i = 0; i<nums.size(); i++)
	{
		min = i;
		for(j = i+1;j<nums.size(); j++)
		{
			if(nums[j] < nums[min])
				min = j;
		}
		swap(nums[i], nums[min]);
	}
}

int main()
{
	vector<int> nums{10, 4, 43, 57, 91, 89, 7, 5};
	selectionSort(nums);
	for(auto it : nums)
		cout<< it << " ";
	
}