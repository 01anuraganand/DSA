#include <iostream>
#include <vector>
using namespace std;

//Recursion
int maximumChocolateR(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{
	if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e9;
	if(i == r-1)
	{
		if(j1 == j2) return grid[i][j1];
		else
			return grid[i][j1] + grid[i][j2];
	}
	
	int mx = -1e9;
	for(int dj1 = -1; dj1 <= 1; dj1++)
	{
		for(int dj2 = -1; dj2 <= 1; dj2++)
		{
			int value = 0;
			if(dj1 == dj2) value = grid[i][j1];
			else
				value = grid[i][j1] + grid[i][j2];
			value += maximumChocolateR(i+1, j1+dj1, j2+dj2, r, c, grid);
			mx = max(mx, value);
		}
		
	}
	return mx;
}

//Memoization
int maximumChocolateM(int i, int j1, int j2, int r, int c,vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
{
	if(j1 < 0 || j2 <  0 || j1 >= c || j2 >= c)	return -1e9;
	if(i == r-1)
	{
		if(j1 == j2) return grid[i][j1];
		else
		{
			return grid[i][j1] + grid[i][j2];
		}
	}
	if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
	int mx = -1e9;
	for(int dj1 = -1; dj1 <= 1; dj1++)
	{
		for(int dj2 = -1; dj2 <= 1; dj2++)
		{
			int value = 0;
			if(dj1 == dj2) value = grid[i][j1];
			else
				value = grid[i][j1] + grid[i][j2];
			value += maximumChocolateM(i+1, dj1+j1, dj2+j2, r, c, grid, dp);
			mx = max(mx, value);
		}
		
	}
	return dp[i][j1][j2] = mx;
}

//Tabulation
int maximumChocolateT(int r, int c, vector<vector<int>> &grid)
{
	vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
	for(int j1 = 0; j1<c; j1++)
	{
		for(int j2 = 0; j2 <c; j2++)
		{
			if(j1 == j2) dp[r-1][j1][j2] = grid[r-1][j1];
			else
				dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
		}
	}
	
	for(int i = r-2; i>=0 ; i--)
	{
		for(int j1 = 0; j1<c; j1++)
		{
			for(int j2 = 0; j2 <c; j2++)
			{
				int mx =  -1e9;
				for(int dj1 = -1; dj1 <= 1; dj1++)
				{
					for(int dj2 = -1; dj2 <= 1; dj2++)
					{
						int value = 0;
						if(j1 == j2) value = grid[i][j1];
						else
							value = grid[i][j1] + grid[i][j2];
						if(dj1+j1 >= 0 && dj1 +j1 < c && dj2+j2 >= 0 && dj2+j2 < c)
							value += dp[i+1][dj1+j1][dj2+j2];
						else
							value += -1e9;
						mx = max(mx, value)	;
					}
				}
				dp[i][j1][j2] = mx;
			}
		}
	}
	return dp[0][0][c-1];
}	


//Space Optimization
int maximumChocolateS(int r, int c, vector<vector<int>> &grid)
{
	vector<vector<int>> front(c, vector<int>(c, 0));
	vector<vector<int>> cur(c, vector<int>(c, 0));
	
	for(int j1 = 0; j1 < c; j1++)
	{
		for(int j2 =0 ; j2 < c; j2++)
		{
			if(j1 == j2) front[j1][j2] = grid[r-1][j1];
			else
				front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
		}	
	}
	
	for(int i = r-2; i >=0 ; i--)
	{
		for(int j1 = 0; j1 < c; j1++)
		{
			for(int j2 = 0; j2 < c; j2++)
			{
				int mx = -1e9;
				for(int dj1 = -1; dj1 <= 1; dj1++)
				{
					for(int dj2 = -1; dj2 <= 1; dj2++)
					{
						int value = 0;
						if(j1 == j2) value = grid[i][j1];
						else
							value = grid[i][j1] + grid[i][j2];
						
						if(dj1+j1 >= 0 && dj1+j1 <c && dj2+j2 >=0 && dj2+j2 <c)
							value += front[dj1+j1][dj2+j2];
						else
							value += -1e9;
						mx = max(mx, value);
					}
				}
				cur[j1][j2] = mx;
			}
		}
		front = cur;
	}
	return front[0][c-1];
}
int main()
{
	vector<vector<int>> grid{
		{2, 3, 1, 2},
		{3, 4, 2, 2},
		{5, 6, 3, 5},
	};
	int r = grid.size();
	int c = grid[0].size();
	cout<<"cherry pickup using recursion:"<<maximumChocolateR(0, 0, c-1, r, c, grid)<<endl;
	
	cout<<"cherry pickup using memoization:";
	vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
	cout<<maximumChocolateM(0, 0, c-1, r, c, grid, dp)<<endl;
	
	cout<<"cherry pickup using tabulation:"<<maximumChocolateT(r, c, grid)<<endl;
	
	cout<<"cherry pickup using Space Optimization:"<<maximumChocolateS(r, c, grid)<<endl;
}