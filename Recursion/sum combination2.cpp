#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findcombination2(int index, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
	if(target == 0)
	{
		ans.push_back(ds);
		return;
	}
	
	for(int i = index; i< arr.size(); i++)
	{
		if (i > index && arr[i]==arr[i-1]) continue;
		if (arr[i] > target) break;
		ds.push_back(arr[i]);
		findcombination2(i+1, target-arr[i], arr, ds, ans);
		ds.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
	sort(arr.begin(), arr.end());
	vector<int> ds;
	vector<vector<int>> ans;
	findcombination2(0, target, arr, ds, ans);
	return ans;
}

int main()
{
	vector<int> arr{1,1,1,2,2};
	int target = 4;
	vector<vector<int>> an = combinationSum2(arr, target);
	for(auto vect1:an)
	{
		cout<<endl;
		for (auto it:vect1)
			cout<<it << " ";
	}
}