#include <iostream>
#include <vector>
using namespace std;

class ArrayArrangement
{
public:
	// Task1: Implement the logic to change arr[i] = index by arr[index] = i;
	void ArrayArrangementNaive(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> nums1(n);
		for(int i = 0; i<n; i++)
		{
			nums1[nums[i]] = i;
		}
		nums = nums1;
	}

	// Task1 : Using optimized approach (when the number is bigger)
	void ArrayArrangementOptimal(vector<int> &nums)
	{
		int i = 0, i0count = 0;
		int n = nums.size();
		for(int i= 0; i<n; i++) // Checking for all element
		{
			if(nums[i]  >= 0)
			{
				int index = nums[i], val = i;
				while(index != i) // It perform the cycle checking by storing indices for movement and correspondingly change the value;
				{
					int moveIndex = nums[index]; // Next Index to move upon
					nums[index] = (val+1)*-1; // Changing the value by its (index+1)*-1
					val = index; 
					index = moveIndex;
				}
				nums[index] = -(val + 1);
			}
		}

		for(int i = 0; i<n; i++)
			nums[i] = nums[i]*-1 -1;
	}


	// Task1 : Using optimized approach (when the number is ~10 ^ 4) 
	// Idea behind this is the (num = N*new_val + old_val) <= N-1, new_val = quotient, old_val = remainder 

	void ArrayArrangementOptimal1(vector<int> &nums)
	{
		int n = nums.size();

		for(int i = 0; i<n; i++)
		{
			int old_val = nums[i] % n;
			nums[old_val] = n * i + nums[old_val];
		}

		for(int i = 0; i<n; i++)
		{
			int n = nums.size();
			nums[i] /= n;
		}
	}

};
int main()
{
	vector<int> nums{5, 1, 3, 0, 2, 4};
	vector<int> nums1, nums2, nums3;
	nums1 = nums2 = nums3 = nums;
	ArrayArrangement obj;
	obj.ArrayArrangementNaive(nums);
	for(auto it: nums)
		cout<< it << " ";
	cout<<endl;


	obj.ArrayArrangementOptimal(nums1);
	for(auto it: nums1)
		cout<< it << " ";
	cout<<endl;


	obj.ArrayArrangementOptimal1(nums2);
	for(auto it: nums2)
		cout<< it << " ";
	cout<<endl;
}