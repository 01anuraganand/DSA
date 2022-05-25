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

vector<vector<int>> permutate(vector<int> &arr)
{
	vector<vector<int>> ans;
	vector<int> ds;
	int freq[arr.size()];
	for(int i = 0; i<arr.size(); i++) freq[i] =0;
	permutation1(ds, arr, ans, freq);
	
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
}