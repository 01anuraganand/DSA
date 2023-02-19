#include <iostream>
#include <vector>
using namespace std;

//Recursion ->top-down approach
//Memoization -> top-down
int fibonacci_dpm(int n, vector<int> &dp)
{
	if (n <=1) return n;
	if(dp[n] != -1) return dp[n];
	return dp[n] = fibonacci_dpm(n-1, dp) + fibonacci_dpm(n-2, dp);
}


//Tabulation -> bottom-up
int fibonacci_dpt(int n, vector<int> &dp)
{
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i<=n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}
int main()
{
	int n;
	cout<<"Enter the value to find fibonacci:"<<endl;
	cin>>n;
	vector<int> dp1(n+1, -1);
	cout<<fibonacci_dpm(n, dp1);
	cout<<endl;
	vector<int> dp2(n+1, -1);
	cout<<fibonacci_dpt(n, dp2);
	
}