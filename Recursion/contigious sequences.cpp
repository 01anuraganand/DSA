#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> printSubArrays(vector<int> arr, int start, int end, vector<vector<int>> &ans)
{
	vector<int> ds;
  
    if (end == arr.size())
        return ans;
    // Increment the end point and start from 0
    else if (start > end)
        printSubArrays(arr, 0, end + 1, ans);
    // Print the subarray and increment the starting point
    else {
        
        for (int i = start; i < end; i++)
			ds.push_back(arr[i]);
        
        ds.push_back(arr[end]);
        ans.push_back(ds);
        printSubArrays(arr, start + 1, end, ans);
    }
    return ans;
}
 
int main()
{
    vector<int> arr = { 1, 2, 3 ,4};
    vector<vector<int>> ans;
   vector<vector<int>> res =  printSubArrays(arr, 0, 0, ans);
   for(auto vec1:res)
   {
   	cout<<endl;
   	for(auto it: vec1)
   		cout<< it << " ";
   }
    return 0;
}