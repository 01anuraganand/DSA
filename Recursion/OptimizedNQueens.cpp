#include <iostream>
#include <vector>
using namespace std;



void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int>
	&leftrow, vector<int> &uppperDiagonal, vector<int> &lowerDiagonal, int n)
{
	if (col == n)
	{
		ans.push_back(board);
		return;
	}
	
	for(int row = 0; row<n; row++)
	{
		if(leftrow[row] == 0 && lowerDiagonal[row+col] == 0 && uppperDiagonal[n-1 + col - row] == 0)
		{
			board[row][col] = 'Q';
			leftrow[row] = 1;
			lowerDiagonal[row + col] = 1;
			uppperDiagonal[n - 1 + col - row] = 1;
			
			solve(col + 1, board, ans, leftrow, uppperDiagonal, lowerDiagonal, n);
			
			board[row][col] = '.';
			leftrow[row] = 0;
			lowerDiagonal[row + col] = 0;
			uppperDiagonal[n - 1 + col - row] = 0;
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
	
	vector<int> leftrow(n, 0), uppperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
	solve(0, board, ans, leftrow, uppperDiagonal, lowerDiagonal, n);
	
	return ans;
}

int main()
{
	int n = 4;
	vector<vector<string>> ans = solveNQueen(n);
	for(int i = 0; i<ans.size(); i++)
	{
		cout<<"Arrangement :"<< i+1 << endl;
		for(int j = 0; j< ans[0].size(); j++)
		{
			cout<< ans[i][j];
			cout<<endl;
		}
	}
	return 0;
}