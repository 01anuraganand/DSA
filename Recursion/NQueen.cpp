#include <iostream>
#include <vector>
using namespace std;

bool isSafeMove(int row, int col, vector<string> &board, int n)
{
	int duprow = row;
	int dupcol = col;
	
	//checking upper left diagonal
	while(row >=0 && col >= 0)
	{
		if (board[row][col] == 'Q')
			return false;
		row--;
		col--;
	}
	
	row = duprow;
	col = dupcol;
	
	// checking row in straight left direction
	while(col >=0)
	{
		if (board[row][col] == 'Q' )
			return false;
		col--;
	}
	
	row = duprow;
	col = dupcol;
	
	//checking diagonal of left corner
	while(row <n && col >=0)
	{
		if (board[row][col] == 'Q')
			return false;
		row++;
		col--;
	}
	
	return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
	if (col == n)	
	{
		ans.push_back(board);
		return;
	}
	
	for(int row = 0; row<n; row++)
	{
		if (isSafeMove(row, col, board, n))
		{
			board[row][col] = 'Q';
			solve(col+1, board, ans, n);
			board[row][col]  = '.';
		}
	}
}

vector<vector<string>> solveNQueen(int n)
{
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n, '.');
	for(int i = 0; i<n; i++)
	{
		board[i] = s;
	}
	solve(0, board, ans, n);
	return ans;
}

int main()
{
	int n = 4;
	vector<vector<string>> ans = solveNQueen(n);
	for(int i = 0; i< ans.size(); i++)
	{
		cout<<"Arrangement :" << i+1 <<endl;
		for(int j = 0; j<ans[0].size(); j++)
		{
			cout<< ans[i][j];
			cout<< endl;
		}
		cout<<endl;
	}
	return 0;
}