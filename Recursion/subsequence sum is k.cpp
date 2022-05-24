#include <iostream>
#include <vector>
using namespace std;

// printing all subsequences sum = k
void sumSequenceKAll(int index, vector<int> &ds, int arr[],int sum, int k, int n)
{
	if (index == n)
	{
		if (sum == k)
			{
				for (auto it: ds)
					cout<< it << " ";
				cout<<endl;
			}
			return;
	}
	
	ds.push_back(arr[index]);
	sum += arr[index];
	sumSequenceKAll(index+1, ds, arr, sum, k, n);
	
	ds.pop_back();
	sum -= arr[index];
	sumSequenceKAll(index+1, ds, arr, sum, k, n);
	
}

bool sumSequenceK1(int index, vector<int> &ds, int arr[], int sum, int k, int n)
{
	if(index == n)
	{
		if (sum == k)
		{
			for (auto it: ds)
				cout<< it << " ";
			cout<<endl;
			return true;
		}
		else return false;
	}
	
	ds.push_back(arr[index]);
	sum += arr[index];
	if (sumSequenceK1(index+1, ds, arr, sum, k, n)==true) return true;
	
	ds.pop_back();
	sum -= arr[index];
	if (sumSequenceK1(index+1, ds, arr, sum, k, n)==true) return true;
	
	return false;
}

int sumSequenceKCount(int index, int arr[], int sum, int k, int n)
{
	if (index == n)
	{
		if (sum == k)
			return 1;
		else
			return 0;
	}
	
	sum +=arr[index];
	int l = sumSequenceKCount(index+1, arr, sum, k, n);
	
	sum -= arr[index];
	int r = sumSequenceKCount(index+1, arr, sum, k, n);
	
	return l+r;
}


int  main()
{
	int arr[] = {1,2,1,1};
	vector<int> ds;
	int k = 3;
	int n = sizeof(arr) /sizeof(arr[0]);
	
	// index, stack, array, initial sum, required sum, N
	sumSequenceKAll(0, ds, arr, 0, k, n);
	
	cout<<endl;
	cout<<sumSequenceK1(0, ds, arr, 0, k, n)<<endl;
	
	cout<<endl;
	cout<<sumSequenceKCount(0, arr, 0, k, n)<<endl;
}