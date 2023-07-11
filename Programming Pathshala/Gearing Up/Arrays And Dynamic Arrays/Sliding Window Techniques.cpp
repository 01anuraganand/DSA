#include <iostream>
#include <vector>
using namespace std;
class SlidingWindow
{
public:
	// To print Subarry sum of size k
	void slidingWindowSubarraySum(vector<int> &nums, int k)
	{
		int sum = 0;
		int n = nums.size();
		for(int i = 0; i<k; i++)
			sum += nums[i];
		for(int j = k; j<n; j++)
		{
			cout<<sum<< " ";
			sum += nums[j];
			sum -= nums[j-k];
		}
		cout<<sum<<endl;
	}

	// Print frequency of x in everay window of size k
	void slidingWindowSubarrayFreq(vector<int> &nums, int k, int x)
	{
		int xFreq = 0;
		int n = nums.size();
		for(int i = 0; i<k; i++)
			if(x == nums[i]) xFreq++;

		for(int j = k; j<n; j++)
		{
			cout<<xFreq<< " ";
			xFreq += x == nums[j];
			xFreq -= x == nums[j-k];
		}
		cout<<xFreq<<endl;
	}

	// Find min swaps required to bring all elements <= x together
	void slidingWindowSubarraySwap(vector<int> &nums, int x)
	{
		int n = nums.size();
		int kLessX = 0;
		for(int i = 0; i<n; i++)
			kLessX += nums[i] <= x;
		
		int maxLegal = 0, legalElement = 0;
		for(int i = 0; i < kLessX; i++)
		{
			legalElement += nums[i] <= x;
			maxLegal = max(maxLegal, legalElement);
		}

		
		for(int i = kLessX; i<n; i++)
		{
			legalElement += nums[i] <= x;
			legalElement -= nums[i-kLessX] <= x;
			maxLegal = max(maxLegal, legalElement);
		}
		cout<<kLessX - maxLegal<<endl; 
	}
};
int main()
{
	vector<int> nums1{7, 1, -5, 3, 6, 4}, nums2{2, 2, 1, 2, 4, 6, 8, 2, 2, 3}, nums3{2, 5, 7, 9, 8, 7, 4};
	SlidingWindow obj;
	obj.slidingWindowSubarraySum(nums1, 3);
	obj.slidingWindowSubarrayFreq(nums2, 4, 2);
	obj.slidingWindowSubarraySwap(nums3, 5);
}