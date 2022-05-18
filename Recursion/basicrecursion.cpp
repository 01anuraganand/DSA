#include <iostream>
using namespace std;

void print1toN(int i, int n)
{	
	if (i > n)
		return ;
	cout<<i<<endl;
	print1toN(i+1, n);
}

void printNto1(int n)
{	
	if (n < 1)
		return ;
	cout<<n<<endl;
	printNto1(n-1);
}

void printBacktrackingNto1(int i, int n)
{	
	if (i > n)
		return ;	
	printBacktrackingNto1(i + 1, n);
	cout<<i<<endl;
}

void printBacktracking1toN(int n)
{	
	if (n < 1)
		return ;
	printBacktracking1toN(n-1);
	cout<<n<<endl;
}

void sumNPara(int i, int sum)
{
	if (i < 1 )
	{	
		cout<<sum;
		return;
	}
	sumNPara(i-1, i + sum);
}

int sumNRecur(int n)
{
	if (n == 0)
		return 0;
	return n + sumNRecur(n-1);
}

int factorial(int n)
{
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

int main()
{
	int n = 5;
	
	print1toN(1, n);
	cout<<endl;
	printNto1(n);
	cout<<endl;
	printBacktrackingNto1(1, n);
	cout<<endl;
	printBacktracking1toN(n);
	cout<<endl;
	sumNPara(n, 0);
	cout<<endl;
	cout<<sumNRecur(n);
	cout<<endl;
	cout<<factorial(n);
	
}