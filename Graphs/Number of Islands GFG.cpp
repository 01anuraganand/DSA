#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfsGrpah(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
{
	queue<pair<int, int>> q;
	visited[row][col] = 1;
	q.push({row, col});
	while(!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for(int delrow = -1; delrow <= 1; delrow++ )
		{
			for(int delcol = -1; delcol <= 1; delcol++)
			{
				int newrow = row + delrow;
				int newcol = col + delcol;
				if(newrow>=0 && newrow<grid.size() && newcol>=0 && newcol < grid[0].size() && !visited[newrow][newcol] && grid[newrow][newcol] == '1')
				{
					visited[newrow][newcol] = 1;
					q.push({newrow, newcol});
				}
			}
		}	
	}
	
}

int numIsIlands(vector<vector<char>> &grid)
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> visited(n, vector<int>(m, 0));
	int count = 0;
	for(int row = 0; row <n; row++)
	{
		for(int col = 0; col<m; col++)
		{
			if(!visited[row][col] && grid[row][col] == '1')
			{
				count++;
				bfsGrpah(row, col, grid, visited);
			}
		}
	}
	return count;
}

int main()
{
	vector<vector<char>> grid{{'0','1','1','0'},{'0','1','1','0'}, {'0','0','1','0'}, {'0','0','0','0'}, {'1','1','0','1'}};
	cout<<numIsIlands(grid);	
}