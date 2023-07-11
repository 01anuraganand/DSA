#include <iostream>
#include <vector>
using namespace std;
int main()
{
	/*
		8
		0 1 0 2 1 3 0 2
		4
	*/
	int n;
	cin>>n;
	vector<long long int> height(n);
	for(int i = 0; i<n; i++)
		cin>>height[i];

	vector<long long int> prefixMax(n), suffixMax(n);
	prefixMax[0] = height[0];
	suffixMax[n-1] = height[n-1];

	for(int i = 1; i<n; i++)
		prefixMax[i] = max(prefixMax[i-1], height[i]);
	
	for(int i = n-2; i>=0 ; i--)
		suffixMax[i] = max(suffixMax[i+1], height[i]);

	long long int waterAmt = 0;
	for(int i = 1; i<n-1; i++)
	{
		long long int deciding_height = min(prefixMax[i-1], suffixMax[i+1]);
		if(height[i]<deciding_height)
			waterAmt += (deciding_height - height[i]);
	}
	cout<<waterAmt<<endl;
}