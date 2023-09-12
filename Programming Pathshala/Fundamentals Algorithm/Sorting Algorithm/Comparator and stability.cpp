#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class ComparatorAndStability
{
public:
	void ascendingOrder(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
	}


	void descendingOrder(vector<int> &nums)
	{
		sort(nums.begin(), nums.end(), [] (int a, int b){return a>b;}); // labmda function
	}

	void ascendingOrderOfMagnitude(vector<int> &nums)
	{
		sort(nums.begin(), nums.end(), [] (int a, int b){return abs(a) < abs(b);});
	}

	void ascendingOrderWithStability(vector<pair<int, int>> &nums)
	{
		sort(nums.begin(), nums.end(), [](pair<int, int> x, pair<int, int> y){
			if(x.first != y.first)
				return x.first < y.first;
			else
				return x.second < y.second;

		});
	}
};

int main()
{
	vector<int> nums{-5, 7, 1, -9};
	ComparatorAndStability obj;
	obj.ascendingOrder(nums);
	for(auto it: nums)
		cout<<it<< " ";
	cout<<endl;
	obj.descendingOrder(nums);
	for(auto it: nums)
		cout<<it<< " ";
	cout<<endl;
	obj.ascendingOrderOfMagnitude(nums);
	for(auto it: nums)
		cout<<it<< " ";

	// value and its occurence time 
	vector<pair<int, int>> nums1{{1, 2}, {2, 2}, {1, 1},  {3, 1}, {2, 1}};
	obj.ascendingOrderWithStability(nums1);
	cout<<endl;
	for(auto it:nums1)
	{
		cout<< it.first << " "<<it.second<<endl;
	}
	cout<<endl;

}