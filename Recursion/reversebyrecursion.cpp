#include <iostream>
using namespace std;

//reverse array using recursion
void reverseby2var(int arr[], int l, int r) 
{	
	if (l >= r)
		return ;
	swap(arr[l], arr[r]);
	reverseby2var(arr, l+1, r-1);
}

void reverse(int arr[], int i, int n)
{
	if (i > n/2)
		return ;
	
	swap(arr[i], arr[n-i-1]);
	reverse(arr, i+1, n);
}



int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	
	int n = sizeof(arr)/ sizeof(int);
	reverseby2var(arr, 0, n-1);
	
	for (int i=0; i<n; i++ )
		cout<<arr[i];
	
	cout<<endl;
	reverse(arr, 0, n);
	for (int i=0; i<n; i++ )
		cout<<arr[i];
	
}