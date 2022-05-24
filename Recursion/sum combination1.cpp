#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of distinct integers candidates and a target integer target, return a list of all 
unique combinations of candidates where the chosen numbers sum to target. You may return the 
combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*/


void findcombination1(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
	if (index == arr.size())
	{
		if (target == 0)
			ans.push_back(ds);
		return;
	}
	
	if (arr[index]<= target)
	{	
		ds.push_back(arr[index]);
		findcombination1(index, target-arr[index], arr, ans, ds);
		ds.pop_back();
	}
	
	findcombination1(index+1, target, arr, ans, ds);
	
}

vector<vector<int>> combinationSum(vector<int> arr, int target)
	{
		vector<vector<int>> ans;
		vector<int> ds;
		findcombination1(0, target, arr, ans, ds);
		return ans;
	}

int main()
{	
	vector<int> arr{2,3,5};
	int target = 8;
	vector<vector<int>> ans = combinationSum(arr, target);
	for(auto vect1d:ans)
	{	
		cout<<endl;
		for(auto it:vect1d)
			cout<<it<<" ";
	}
	
}
