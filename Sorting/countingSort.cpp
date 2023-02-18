#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void countingSort(vector<int> &nums)
{
	int maxNumber = *(max_element(nums.begin(), nums.end()));
	vector<int> count(maxNumber+1, 0);
	for(int i = 0; i<nums.size(); i++)
	{
		count[nums[i]]++;
	}
	int j = 0;
	for(int i = 0; i<=maxNumber; i++)
	{
		
		while(count[i]--)
		{
			nums[j++] = i;
		}
	}
}
int main()
{
	vector<int> nums{8, 89, 3, 53, 0, 0, 4, 7, 3, 78, 2, 2, 1, 1};
	countingSort(nums);
	for(auto it: nums)
		cout<< it << " ";
}