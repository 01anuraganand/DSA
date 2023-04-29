#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(int index, int N, vector<int> &nums)
{
	int largest = index;
	int l = 2*index + 1;
	int r = 2*index + 2;
	
	//If left child is larger than root
	if(l < N && nums[l] > nums[largest]) 
		largest = l;
	
	//If right child is larget than root
	if(r < N && nums[r] > nums[largest])
		largest = r;
	
	//If largest does not equal to root index
	if(largest != index)
	{
		swap(nums[index], nums[largest]);
		maxHeapify(largest, N, nums);
	}
}


void heapSort(vector<int> &nums)
{
	int N = nums.size();
	//Build Heap
	for(int i = N/2 - 1; i>=0; i--)
		maxHeapify(i, N, nums);
	
	for(int i = N-1; i >0; i--)
	{
		swap(nums[0], nums[i]);
		
		maxHeapify(0, i, nums);
	}
}

int main()
{
	vector<int> nums{89, 1, 38, 20, 199, 150, 0};
	heapSort(nums);
	for(auto it: nums)
		cout<<it<<" ";
}