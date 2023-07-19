#include <iostream>
#include <vector>
using namespace std;
class CountingTriplets
{
public:
	int countTripletsBruteFoce(vector<int> &nums, int m)
	{
		int n = nums.size();
		int count = 0;
		for(int i = 0; i<n; i++)
		{
			for(int j = i+1; j<n; j++)
			{
				for(int k = j+1; k<n; k++)
				{
					if((nums[i] + nums[j] + nums[k]) % m == 0)
						count++;
				}
			}
		}
		return count;
	}

	int countTripletsOptimal(vector<int> &nums, int m)
	{
		vector<int> counts(m, 0);
		int n = nums.size();
		for(auto val : nums)
			counts[val%m]++;

		int ans = 0;
		for(int i = 0; i<n; i++)
		{
			for(int j = i; j<n; j++)
			{
				int k;
				if((i + j)%m == 0) k = 0;
				else k = (m-(i+j)%m);
				if(k < j) continue;

				if(i == j && j == k)
					ans += counts[i]*(counts[i]-1)*(counts[i]-2)/6;
				else if(i == j)
					ans += counts[i]*(counts[i]-1)/2*counts[k];
				else if(i == k)
					ans += counts[i]*(counts[i]-1)/2*counts[j];
				else if(j == k)
					ans += counts[j]*(counts[j]-1)/2*counts[i];
				else
					ans += counts[i]*counts[j]*counts[k];
			}
		}
		return ans;
	}
};
int main()
{
	CountingTriplets obj;
	vector<int> nums{2, 3, 4, 5, 1, 8};
	int m = 8;
	cout<<obj.countTripletsBruteFoce(nums, m)<<endl;
	cout<<obj.countTripletsOptimal(nums, m)<<endl;

}