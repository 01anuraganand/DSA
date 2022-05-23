#include <iostream>
#include <vector>
using namespace std;

// printing all subsequences 
void subsequence(int index, vector<int> &ds, int arr[], int n)
{
	if (index == n)
	{
		for(auto it: ds)
		{
			cout<< it << " ";
		}
		if (ds.size() == 0)
		{
			cout<< "{}";
		}
		cout<<endl;
		return;
	}
	
	ds.push_back(arr[index]);
	subsequence(index+1, ds, arr, n);
	
	ds.pop_back();
	subsequence(index+1, ds, arr, n);
}

int main()
{
	int arr[] = {3,1,2};
	vector<int> ds;
	subsequence(0, ds, arr, 3);
}
