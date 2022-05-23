#include <iostream>

using namespace std;

// fibonacci number 
int fibonacci_recursion(int n)
{
	if (n <= 1) return n;
	int last = fibonacci_recursion(n-1);
	int slast = fibonacci_recursion(n-2);
	return last + slast;
}

int main()
{
	int n = 6;
	cout<<fibonacci_recursion(n);
	
}