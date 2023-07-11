#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
class MaxGapProblem
{
public:
	int MaxGapProblemBucketing(vector<int> &nums)
	{

		int n = nums.size();
		if (n < 2) return 0;
		int minNum = *min_element(nums.begin(), nums.end());
		int maxNum = *max_element(nums.begin(), nums.end());
		// pair as {minimum element, maximum element}
		vector<pair<int, int>> bucket(n, make_pair(INT_MAX, INT_MIN)); // pair<int, int>({INT_MAX, INT_MIN})

		if(minNum == maxNum) return 0;
		int gap = (maxNum - minNum)/(n-1); // maximum gap that may feasible
		if((maxNum - minNum)%(n-1) != 0) gap++;

		for(int i = 0; i<n; i++)
		{
			int bucketNum = (nums[i] - minNum)/gap; // Important point to ponder upo

			bucket[bucketNum].first = min(bucket[bucketNum].first ,nums[i]);
			bucket[bucketNum].second = max(bucket[bucketNum].second, nums[i]);
		}


		int ans = INT_MIN;
		int prev = INT_MIN;
		
		for(int i = 0; i<n; i++)
		{
			if(bucket[i].first == INT_MAX) continue;

			if(prev == INT_MIN) prev = bucket[i].second;

			else
			{
				ans = max(ans, bucket[i].first - prev);
				prev = bucket[i].second;
			}
		}

		return ans;
		
	}
};

int main()
{
	vector<int> nums{65, 25, 27, 33, 25, 70};
	MaxGapProblem obj;
	cout<<obj.MaxGapProblemBucketing(nums);
}