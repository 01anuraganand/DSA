/*
Pre Computation Techniques 
1. Find the subQueries Range Sum
2. Find the maximum in subQueries Range
*/

#include <iostream>
#include <vector>
using namespace std;
class RangeQueries
{
public:
    void rangeSum(vector<int> &nums, vector<pair<int, int>> & queries)
    {
        // Store the prefix sum
        for(int i = 1; i<nums.size(); i++)
        {
            nums[i] += nums[i-1];
        }


        for(int i = 0; i<queries.size(); i++)
        {
            int l = queries[i].first;
            int r = queries[i].second;
            if(l == 0) cout<<nums[r]<< " ";
            else
                cout<<nums[r] - nums[l-1]<<" ";
        }
        
        cout<<endl;
    }

    void maxInRange(vector<int> & nums, vector<pair<int, int>> & queries)
    {
        int mx = nums[0];
        for(int i = 1; i<nums.size();i++)
        {
            if(nums[i] > mx)
                mx = nums[i];
            nums[i] = mx;
        }

        for(int i = 0; i<queries.size(); i++)
        {
            int l = queries[i].first;
            int r = queries[i].second;
            cout<<nums[r]<< " ";
        }
        cout<<endl;
    }
};
int main()
{
    vector<int> nums{5, 8, 0, 9, 3, 19, 7, 3 };
    vector<int> num1 = nums;
    vector<pair<int, int>> queries{{0, 2}, {0, 4}, {1, 5}, {3, 6}, {5, 7}};
    RangeQueries obj;
    
    obj.rangeSum(nums, queries);
    obj.maxInRange(num1, queries);
}