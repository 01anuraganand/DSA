#include <iostream>
using namespace std;
//Return garbage value;
int* traverse()
{
	int arr[5], x = 2;
	for(int i = 0; i<5; i++)
	{
		arr[i] = x;
		x *= 2;
	}
	return arr; // return first address only and all other contigious address gets vanished because the function calling gets out of stack execution order and hence no variable remains (give garbage value).
}
int* traverse1()
{
	static int arr[5], x = 2; //static hold the memory even after the funtion get over
	for(int i = 0; i<5; i++)
	{
		arr[i] = x;
		x *= 2;
	}
	return arr; 
}
int main()
{
	int* ptr;
	ptr = traverse1();
	for(int i = 0; i<5; i++)
	{
		cout<<*(ptr + i)<< "  ";
	}
	cout<<endl;
}