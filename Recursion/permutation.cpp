#include <iostream>
#include <vector>
using namespace std;

void permutation1(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[])
{
	if (ds.size() == arr.size())
	{
		ans.push_back(ds);
		return;
	}
	for(int i = 0; i<arr.size(); i++)
	{
		if(!freq[i])
		{
			ds.push_back(arr[i]);
			freq[i] = 1;
			permutation1(ds, arr, ans, freq);
			freq[i] = 0;
			ds.pop_back();
		}
	}
}

void permutation2(int index, vector<int> &arr, vector<vector<int>> &ans)
{
	if( index == arr.size())
	{
		ans.push_back(arr);
		return;
	}
	
	for(int i = index; i<arr.size(); i++)
	{
		swap(arr[index], arr[i]);
		permutation2(index+1, arr, ans);
		swap(arr[index], arr[i]);
	}
}

vector<vector<int>> permutate(vector<int> &arr)
{
	vector<vector<int>> ans;
	vector<int> ds;
	int freq[arr.size()] = {0};
	permutation1(ds, arr, ans, freq);
	return ans;
}

vector<vector<int>> permutate2(vector<int> &arr)
{
	vector<vector<int>> ans;
	permutation2(0, arr, ans);
	return ans;
}

int main()
{
	vector<vector<int>> ans;
	vector<int> arr{1,2,3};
	ans = permutate(arr);
	for (auto vec1:ans)
	{
		cout<<endl;
		for(auto it: vec1)
			cout<<it<< " ";
	}
	
	
	cout<<endl;
	vector<vector<int>> ans1;
	ans1 = permutate2(arr);
	for (auto vec1:ans1)
	{
		cout<<endl;
		for(auto it: vec1)
			cout<<it<< " ";
	}
}