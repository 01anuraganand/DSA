#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int rottenOrages(vector<vector<int>> &grid)
{
	int n = grid.size();
	int m = grid[0].size();
	// {{row, col}, time}
	queue<pair<pair<int, int>, int>> q;
	vector<vector<int>> visited(n, vector<int>(m,0));
	
	int countFresh = 0;
	for(int i = 0; i<grid.size(); i++)
	{
		for(int j = 0; j<grid[0].size(); j++)
		{
			if(grid[i][j] == 2)
			{
				q.push({{i,j}, 0});
				visited[i][j] = 2;
			}
			else
				visited[i][j] = 0;
			if(grid[i][j] == 1) countFresh++;
		}
	}
	
	int tm = 0;
	int delRow[] = {-1, 0, 1, 0};
	int delCol[] = {0, 1, 0, -1};
	int count = 0;
	
	while(!q.empty())
	{
		int row = q.front().first.first;
		int col = q.front().first.second;
		int time = q.front().second;
		
		tm = max(tm, time);
		q.pop();
		for(int i = 0; i<4; i++)
		{
			int newrow = row + delRow[i];
			int newcol = col + delCol[i];
			if(newrow>=0 && newrow <n && newcol >=0 && newcol <m && visited[newrow][newcol] == 0 && grid[newrow][newcol] == 1)
			{
				q.push({{newrow, newcol}, time+1});
				visited[newrow][newcol] = 2;
				count++;
			}
		}
		
	}
	if(count != countFresh) return -1;
	return tm;
}

int main()
{
	vector<vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
	//vector<vector<int>> grid{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
	
	cout<<rottenOrages(grid);
}

