#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class RotateTheArraybyK
{
public:
    // Naive Solution - TC : O(k.N)
    void rotateArrayNaive(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        while(k > 0)
        {
            int last = nums[n-1];
            for(int i = n-1; i > 0; i--)
            {
                nums[i] = nums[i-1];
            }
            nums[0] = last;
            k--;
        }
    }

    //Rotate by using temporary array TC: O(N) SC : O(N)
    void rotateArraybyTempArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        vector<int> temp(n);
        
        int i;
        for(i = 0; i<n; i++)
            temp[(i+k)%n] = nums[i];
        
        nums = temp;
    }


    // Think in gready approach by firstly reversing the full array and then reversing 
    //(begin, begin + k) and (begin + k, end); TC - Reverse(N) + Reverse(N) = O(2N)
    void rotateArrayReverse(vector<int> &nums2, int k)
    {
        k %= nums2.size();
        reverse(nums2.begin(), nums2.end());
        reverse(nums2.begin(), nums2.begin()+k);
        reverse(nums2.begin()+k, nums2.end());
    }


};
int main()
{
    int n, k;
    cin>>n >> k;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
        cin>>nums[i];
    vector<int> nums1, nums2, nums3;
    nums1 = nums2 = nums3 = nums;


    RotateTheArraybyK obj;
    obj.rotateArrayNaive(nums1, k);
    for(auto it: nums1)
        cout<<it << " ";
    cout<<endl;


    obj.rotateArraybyTempArray(nums3, k);
    for(auto it : nums3)
        cout<<it << " ";
    cout<<endl;

    obj.rotateArrayReverse(nums2, k);
    for(auto it : nums2)
        cout<<it << " ";
    cout<<endl;



}