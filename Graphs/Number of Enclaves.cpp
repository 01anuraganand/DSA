#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int numberOfEnclaves(vector<vector<int>> grid)
{
	int n = grid.size();
	int m = grid[0].size();
	queue<pair<int, int>> q;
	vector<vector<int>> visited(n, vector<int> (m, 0));
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(i == 0 || i == n-1 || j == 0 || j == m-1)
			{
				if(grid[i][j] == 1)
				{
					q.push({i, j});
					visited[i][j] = 1;
				}
			}
		}
	}
	
	
	int delRow[] = {-1, 0, 1, 0};
	int delCol[] = {0, 1, 0, -1};
	
	while(!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++)
		{
			int newrow = row + delRow[i];
			int newcol = col + delCol[i];
			if(newrow>= 0 && newrow<n && newcol >=0 && newcol <m && !visited[newrow][newcol] && grid[newrow][newcol] == 1)
			{
				q.push({newrow, newcol});
				visited[newrow][newcol] = 1;
			}
		}
	}
	
	int count = 0;
	for(int i = 0; i<n; i++)
	{
		for(int j =0; j<m; j++)
		{
			if(grid[i][j] == 1 && visited[i][j] == 0)
				count++;
		}
	}
	return count;
}

int main()
{
	vector<vector<int>> grid{
		{0, 0, 0, 1}, 
		{1, 0, 0, 1},
		{0, 1, 1, 0}, 
		{0, 0, 0, 1}
	};
	cout<<"Number of Enclaves:"<<numberOfEnclaves(grid);
}