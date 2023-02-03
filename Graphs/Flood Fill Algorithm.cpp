#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &images, vector<vector<int>> &ans, int delRow[], int delCol[], int color ,int newcolor)
{
	ans[row][col] = newcolor;
	
	for(int i = 0; i<4; i++)
	{
		int newrow = row + delRow[i];
		int newcol = col + delCol[i];
		if( newrow >=0 && newrow < images.size() && newcol < images[0].size() && images[newrow][newcol] == color && ans[newrow][newcol] != newcolor)
		{
			dfs(newrow, newcol, images, ans, delRow, delCol, color, newcolor);
		}
	}
}
vector<vector<int>> flooFill(int startRow, int startCol, vector<vector<int>> &images, int newcolor)
{
	int startColor = images[startRow][startCol];
	vector<vector<int>> ans = images;
	int color = images[startRow][startCol];
	int delRow[4] = {-1, 0, 1, 0};
	int delCol[4] = {0, 1, 0, -1};
	dfs(startRow, startCol, images, ans, delRow, delCol, startColor, newcolor);
	return ans;
}

int main()
{
	vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	vector<vector<int>> ans = flooFill(1,1,image, 2);
	for(auto vec1: ans)
	{
		cout<<endl;
		for(auto it: vec1)
			cout<< it << " ";
	}
}