#include <iostream>
#include <vector>
using namespace std;
class MaxChunksToMakeSorted
{
public:

    //helper function for Naive Approach
    bool checkChunks(vector<int> &nums, int i, int j)
    {
        int count = 0;
        for(int k = i; k <= j; k++)
        {
            if(nums[k] >= i && nums[k] <= j)
                count++;
        }
        return count == (j - i + 1);
    }
    
    // Naive Approach
    int maxChunks1(vector<int> &nums)
    {   
        int n = nums.size();
        int i = 0, ans = 0, j;
        while(i < n)
        {
            for(j = i; j<n; j++)
            {
                if(checkChunks(nums,i, j))
                    break;
            }
            i = j + 1;
            ans++;
        }
        return ans;
    }
    
    //Optimized Approach with prefixMax
    int maxChunks2(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];
        for(int i = 1; i<n; i++)
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(prefixMax[i] == i)
                count++;
        }
        return count;
    }

    // Optimized Approach with max variable
    int maxChunks3(vector<int> &nums)
    {
        int n = nums.size();
        int mx = nums[0];
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] > mx)
                mx = nums[i];
            if( mx == i)
                count++;
        }
        return count;   
    }
};


bool checkSortedPer(int i, int j)
{

}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
        cin>>nums[i];

    MaxChunksToMakeSorted obj;
    cout<<obj.maxChunks1(nums)<<endl;
    cout<<obj.maxChunks2(nums)<<endl;
    cout<<obj.maxChunks3(nums)<<endl;
    

    
}