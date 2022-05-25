#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

void subsetsum2(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{

	ans.push_back(ds);
	
	for (int i = index; i< arr.size(); i++)
	{
		if (i != index && arr[i]==arr[i-1]) continue;
		
		ds.push_back(arr[i]);
		subsetsum2(i+1, arr, ds, ans);
		
		ds.pop_back();
				
	}
	
}


int main()
{
	vector<int> arr{1,2,2};
	vector<int> ds;
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	subsetsum2(0, arr, ds, ans);
	for(auto vec1:ans)
	{
		cout<<endl;
		for (auto it:vec1)
			cout<< it << " ";
	}
		
}