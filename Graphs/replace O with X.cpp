#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>> & matrix, vector<vector<int>> &visited, int delRow[], int delCol[])
{
	visited[row][col] = 1;
	int n = matrix.size();
	int m = matrix[0].size();
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			int newrow = row + delRow[i];
			int newcol = col + delCol[i];
			if(newrow >=0 && newrow <n && newcol >=0 && newcol <m && !visited[newrow][newcol]  && matrix[newrow][newcol] == 'O')
			{
				dfs(newrow, newcol, matrix, visited, delRow, delCol);
			}
		}
	}
}

vector<vector<char>> replaceOwithX(int n, int m, vector<vector<char>> &matrix)
{
	int delRow[] = {-1, 0, 1, 0};
	int delCol[] = {0, 1, 0, -1};
	vector<vector<int>> visited(n, vector<int> (m, 0));
	
	for(int j = 0; j<m; j++)
	{
		if(!visited[0][j] && matrix[0][j] == 'O')
			dfs(0, j, matrix, visited, delRow, delCol);
		
		if(!visited[n-1][j] && matrix[n-1][j] == 'O')
			dfs(n-1, j, matrix, visited, delRow, delCol);
	}
	
	for(int i = 0; i<n; i++)
	{
		if(!visited[i][0] && matrix[i][0] == 'O')
			dfs(i, 0, matrix, visited, delRow, delCol);
		
		if(!visited[i][m-1] && matrix[i][m-1] == 'O')
			dfs(i, m-1, matrix, visited, delRow, delCol);
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
			if(!visited[i][j] && matrix[i][j] == 'O')
				matrix[i][j] = 'X';
	}
	
	return matrix;
	
}

int main()
{
	vector<vector<char>> matrix	{
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'X', 'X'}, 
		{'X', 'O', 'O', 'X'}, 
		{'X', 'O', 'X', 'X'}, 
		{'X', 'X', 'O', 'O'}
	};
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<char>> ans = replaceOwithX(n, m, matrix);
	
	for(auto vec1: ans)
	{
		for(auto it : vec1)
			cout<< it << " ";
		cout<<endl;
	}
}