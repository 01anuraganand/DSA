#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	long long int p, q, r;
	cin>> n >> p >> q >> r;
	vector<long long int> nums(n);
	for(int i = 0; i<n; i++)
		cin>>nums[i];	
	
	vector<long long int> maxLeft(n), minLeft(n);

	maxLeft[0] = minLeft[0] = nums[0];
	for(int i = 1; i<n; i++)
	{
		minLeft[i] = min(minLeft[i-1], nums[i]);
		maxLeft[i] = max(maxLeft[i-1], nums[i]);
	}
	
	vector<long long int> maxRight(n), minRight(n);
	maxRight[n-1]  = minRight[n-1] = nums[n-1];
	for(int i = n-2; i>= 0; i--)
	{
		minRight[i] = min(minRight[i+1], nums[i]);
		maxRight[i] = max(maxRight[i+1], nums[i]);
	}
	long long int ans = LLONG_MIN;
	for(int i = 0; i<n; i++)
	{
		long long int maxLeftVal = p < 0 ? minLeft[i] : maxLeft[i];
		long long int maxRightVal = r < 0 ? minRight[i] : maxRight[i];
		ans = max(ans, p*maxLeftVal + q*nums[i] + r*maxRightVal);
	}
	cout<<ans<<endl;
}