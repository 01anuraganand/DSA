#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> isPrime(n+1, 1);
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(int i = 2; i*i<= n+1; i++)
	{
		if(isPrime[i])
		{
			for(int j = i; j*i<= n+1; j++)
				isPrime[i*j] = 0;
		}
	}
	if(n>2)
		cout<<2<<endl;
	else
		cout<<1<<endl;
	for(int i = 2; i<= n+1; i++)
		if(!isPrime[i])
			cout<<2<<" ";
		else
			cout<<1<<" ";
	cout<<endl;
}