#include <iostream>
#include <vector>
using namespace std;

//Recursion
int ninjaTrainingR(int day, int last, vector<vector<int>> & points)
{
	if(day == 0)
	{
		int mx = 0;
		for(int task = 0; task < 3; task++)
			mx = max(mx, points[0][task]);
		return mx;
	}
	
	int mx = 0;
	for(int task = 0; task < 3; task++)
	{
		if(task != last)
		{
			int point = points[day][task] + ninjaTrainingR(day-1, task, points);
			mx = max(mx, point);
		}
	}
	return mx;
}

//Memoization
int ninjaTrainingM(int day, int last, vector<vector<int>> & points, vector<vector<int>> &dp)
{
	if(day == 0)
	{
		int mx = 0;
		for(int task = 0; task < 3; task++)
		{
			if(task != last)
				mx = max(mx, points[0][task]);
		}
		return mx;
	}
	if(dp[day][last] != -1) return dp[day][last];
	
	int mx = 0;
	
	for(int task = 0; task < 3; task++)
	{
		if(task != last)
		{
			int point = points[day][task] + ninjaTrainingM(day-1, task, points, dp);
			mx = max(mx, point);
		}
	}
	return dp[day][last] = mx;
	
}


//Tabulation
int ninjaTrainingT(int n, vector<vector<int>> &points)
{
	vector<vector<int>> dp(n, vector<int>(4, 0));
	dp[0][0] = max(points[0][1], points[0][2]);
	dp[0][1] = max(points[0][0], points[0][2]);
	dp[0][2] = max(points[0][1], points[0][1]);
	dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));
	
	for(int day = 1; day < n; day++)
	{
		for(int last = 0; last < 4; last++)
		{
			dp[day][last] = 0;
			for(int task = 0; task<3; task++)
			{
				if(task != last)
				{
					int point = points[day][task] + dp[day-1][task];
					dp[day][last] = max(dp[day][last], point);
				}
			}
			
		}
		
	}
	return dp[n-1][3];
}

//Space Optimization
int ninjaTrainingS(int n, vector<vector<int>> &points)
{
	vector<int> prev(4, 0);
	prev[0] = max(points[0][1], points[0][2]);
	prev[1] = max(points[0][0], points[0][2]);
	prev[2] = max(points[0][0], points[0][1]);
	prev[3] = max(points[0][1], max(points[0][1], points[0][2]));
	
	for(int day = 1; day < n; day++)
	{
		vector<int> temp(4, 0);
		for(int last = 0; last < 4; last++)
		{
			temp[last] = 0;
			for(int task = 0; task < 3; task++)
			{
				if(task != last)
					temp[last] = max(temp[last], points[day][task] + prev[task]);
			}
		}
		prev = temp;
	}
	return prev[3];
}

int main()
{
	vector<vector<int>> points{{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
	int n = points.size();
	cout<<"Recursion:"<<ninjaTrainingR(n-1, 3, points)<<endl;
	
	vector<vector<int>> dp(n, vector<int>(4, -1));
	cout<<"Memoization:"<<ninjaTrainingM(n-1, 3, points, dp)<<endl;
	
	
	cout<<"Tabulation:"<<ninjaTrainingT(n, points)<<endl;
	
	cout<<"Space Optimization:"<<ninjaTrainingS(n, points)<<endl;
}