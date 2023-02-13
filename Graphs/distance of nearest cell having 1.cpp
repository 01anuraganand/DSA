#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> nearest1(vector<vector<int>> &grid)
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> visited(n, vector<int>(m, 0));
	vector<vector<int>> distance(n, vector<int>(m, 0));
	queue<pair<pair<int, int>, int>> q; // row, col, step
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
			if(grid[i][j] == 1)
			{
				q.push({{i, j}, 0});
				visited[i][j] = 1;
			}
	}
	
	int delRow[] = {-1, 0, 1, 0};
	int delCol[] = {0, 1, 0, -1};
	
	while(!q.empty())
	{
		int row = q.front().first.first;
		int col = q.front().first.second;
		int step = q.front().second;
		
		q.pop();
		distance[row][col] = step;
		for(int i = 0; i<4; i++)
		{
			
			int newrow = row + delRow[i];
			int newcol = col + delCol[i];
			if(newrow <n && newrow>=0 && newcol <m && newcol >=0 && visited[newrow][newcol] == 0)
			{
				visited[newrow][newcol] = 1;
				q.push({{newrow, newcol}, step+1});
			}
		}
	}
	return distance;
}

int main()
{
	vector<vector<int>> grid{
		{1, 0, 1},
		{1, 1, 0},
		{1, 0, 0}
	};
	
	vector<vector<int>> ans =  nearest1(grid);
	for(auto vec1: ans)
	{
		for(auto it : vec1)
			cout<< it << " ";
		cout<<endl;
	}
	
}