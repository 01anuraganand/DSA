#include <iostream>
#include <vector>
using namespace std;
class CountingPairs
{
public:
	/*
	given an integer array 'Arr[N]' and an integer ‘k’. 
	We have to find the total number of pairs (i, j) such that (Arr[i]+Arr[j]) is divisible by ‘k’ where i≠j, Arr[i]>=0.
	*/
	// TC : O(N*N)
	int countingPairsNaive(vector<int> &nums, int k)
	{
		int count = 0;
		for(int i = 0; i<nums.size(); i++)
		{
			for(int j = i+1; j<nums.size(); j++)
				if((nums[i] + nums[j])%k == 0)
					count++;
		}
		return count;
	}

	// Concept of nCr and remainder TC : O(N+k)
	int countingPairsOptimal(vector<int> &nums, int k)
	{
		int n = nums.size();
		vector<int> counts(n, 0);
		for(int i = 0; i<n; i++)
		{
			counts[nums[i]%k]++;
		}

		int ans = counts[0]*(counts[0]-1)/2;
		for(int i = 1; i<= (k/2 -1); i++)
		{
			ans += (counts[i]*counts[k-i]);			
		}
		if(k % 2 == 0)
			ans += (counts[k/2]*counts[k/2]-1)/2;
		else
			ans += (counts[k/2]*counts[k/2+1]);

		return ans;
	}

};
int main()
{
	CountingPairs obj;
	vector<int> nums{2, 2, 4, 3, 5};
	int k = 2;
	cout<<obj.countingPairsNaive(nums, k)<<endl;
	cout<<obj.countingPairsOptimal(nums, k)<<endl;

}