#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class SearchKeyInSortedMatrix
{
public:

	// Brute Force Approach TC: O(n*m)
	pair<int, int> SearchKeyInSortedMatrixBruteForce(vector<vector<int>> &matrix, int key)
	{
		int n = matrix.size();
		int m = matrix[0].size();
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
				if(matrix[i][j] == key)
					return {i, j};
		}
		return {-1, -1};
	}


	// Searching by using binary search concept TC : O(n*logn)
	int binarySearch(vector<int> nums, int key)
	{
		int n = nums.size();
		int low = 0, high = n-1;
		while(low <= high)
		{
			int mid = (low + high)/2;
			if(nums[mid] == key)
				return mid;
			if(nums[mid] > key)
				high = mid -1;
			else
				low = mid + 1;
		}
		return -1;
	}

	pair<int, int> SearchKeyInSortedMatrixBinarySearch(vector<vector<int>> &matrix, int key)
	{
		int n = matrix.size();
		int m = matrix[0].size();
		for(int i= 0; i<n; i++)
		{
			int ans = binarySearch(matrix[i], key);
			if(ans != -1) return {i, ans};
		}
		return {-1, -1};
	}


	// Optimal Approach to start from either [N-1][0] or [0][N-1] and eliminate row and column TC: O(m+n)
	pair<int, int> SearchKeyInSortedMatrixOptimal(vector<vector<int>> &matrix, int key)
	{
		int n = matrix.size();
		int m = matrix[0].size();
		int i = 0, j = n-1;
		while(i < m-1 && j >= 0)
		{
			if(matrix[i][j] == key)
				return {i, j};
			if(matrix[i][j] > key)
				j--;
			else
				i++;
		}
		return {-1, -1};
	}

};
int main()
{
	vector<vector<int>> matrix{
		{10, 20, 30, 40},
		{15, 25, 35, 45}, 
		{22, 28, 38, 50}
	};
	int key = 28;

	SearchKeyInSortedMatrix obj;
 	pair<int, int> ans = obj.SearchKeyInSortedMatrixBruteForce(matrix, key);
 	cout<<ans.first << " "<<ans.second<<endl;

 	ans = obj.SearchKeyInSortedMatrixBinarySearch(matrix, key);
 	cout<<ans.first << " "<<ans.second<<endl;

 	ans = obj.SearchKeyInSortedMatrixOptimal(matrix, key);
 	cout<<ans.first << " "<<ans.second<<endl;




}