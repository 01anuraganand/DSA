/*
Given an integer array nums, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. 
If frequencies of two elements are same, then smaller number comes first.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Triplet{
    int val;
    int freq;
    int index;
};
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i<n; i++) cin>>nums[i];
        
        int fre[101] = {0};
        for(int i = 0; i<n; i++)
            fre[nums[i]]++;
        
        vector<Triplet> ValfreqIndex;
        for(int i = 0; i<n; i++)
        {
            Triplet t;
            t.val = nums[i];
            t.freq = fre[nums[i]];
            t.index = i;
            ValfreqIndex.push_back(t);
        }
        
        sort(ValfreqIndex.begin(), ValfreqIndex.end(), [](Triplet t1, Triplet t2 ){
           if(t1.freq != t2.freq)
                return t1.freq > t2.freq;
            if(t1.val != t2.val)
                return t1.val < t2.val;
            return t1.index < t2.index;
        });
        
        for(int i = 0; i<n; i++)
        {
            cout<< ValfreqIndex[i].val<<" ";
        }
        cout<<endl;
    }
    return 0;
}