#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> & vec, int startRow, int startCol, int n, int m)
{
	visited[row][col] = 1;
	vec.push_back({row - startRow, col - startCol});
	
	int delRow[] = {-1, 0, 1, 0};
	int delCol[] = {0, 1, 0, -1};
	
	for(int i = 0; i<4; i++)
	{
		int newrow = row + delRow[i];
		int newcol = col + delCol[i];
		if(newrow>=0 && newrow<n && newcol >=0 && newrow <m && !visited[newrow][newcol] && grid[newrow][newcol] == 1)
		{
			dfs(newrow, newcol,grid, visited, vec, startRow, startCol, n, m);
		}
	}
}

int countDistinctIsland(vector<vector<int>> &grid)
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> visited(n, vector<int> (m, 0));
	set<vector<pair<int, int>>> sett;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(!visited[i][j] && grid[i][j] == 1)
			{
				vector<pair<int, int>> vec;
				dfs(i, j, grid, visited, vec, i, j, n, m);
				sett.insert(vec);
			}
		}
	}
	return sett.size();
}

int main()
{
	vector<vector<int>> grid{
		{1, 1, 0, 0 ,1}, 
		{1, 1, 0, 0, 0},
		{0, 0, 0, 1, 1},
		{1, 1, 0, 1, 1}
	};
	cout<<"Number of Distinct Island:"<<countDistinctIsland(grid);
	
}