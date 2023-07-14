#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class PrimalityTest
{
public:
	bool isPrimeBruteForce(int N)	
	{
		int count = 0;
		for(int i = 1; i<=N; i++)
			if(N % i == 0)
				count++;
		return count == 2;
	}

	// Checking for sqrt(N), if first halft of N is having factor, 
	// then second haft must also have, if it had it must not be prime number
	bool isPrimeOptimal(int N)
	{
		if(N == 1) return false;
		for(int i = 2; i<= sqrt(N); i++)
		{
			if(N%i == 0)
				return false;
		}
		return true;
	}

	// Checking the number whether it is prime number or not in range 1 to N TC : O(N.log(log(N)))
	void isPrimeSeiveOfEratosthens(int N)
	{
		vector<int> prime(N+1, 1);
		for(int i = 2; i<= sqrt(N); i++ )
		{
			if(prime[i])
			{
				for(int j = i; j*i<=N; j++)
					prime[j*i] = 0;
			}
		}

		for(int i = 2; i<=N; i++)
		{
			if(prime[i] == 1)
				cout<< i << " ";
		}
		cout<<endl;

	}
};

int main()
{
	int N = 17;
	PrimalityTest obj;
	cout<<obj.isPrimeBruteForce(N)<<endl;
	cout<<obj.isPrimeOptimal(N)<<endl;
	obj.isPrimeSeiveOfEratosthens(101);
}