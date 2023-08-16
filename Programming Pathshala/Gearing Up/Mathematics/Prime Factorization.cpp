#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class PrimeFactorization
{
public:
	// Brute Foce Approach TC : O(N+log2(N))
	void primeFactorizationBruteForce(int N)
	{
		int num = N;
		for(int i = 2; i<= num; i++)
		{
			while(N%i == 0)
			{
				cout<<i << " ";
				N /= i;
			}
		}
		cout<<endl;
	}

	// Optimal Brute Force TC : O(sqrt(N) + log(N))
	void primeFactorizationOptimalBruteFoce(int N)
	{
		int num = N;
		for(int i = 2; i<= sqrt(num); i++)
		{
			while(N%i == 0)
			{
				cout<<i << " ";
				N /= i;
			}
		}
		if(N != 1)
			cout<<N<<endl;
		cout<<endl;
	}

	// Fastest Prime Factorization using Sieve of Erastosthenes TC : N(log(log(N))) + Q (queries)
	void primeFactorizationSeive(int n, vector<int> &queries)
	{
		
		vector<int> isPrime(n+1, 1);
		vector<int> smallestPrimeFactor(n+1, -1);
		isPrime[0] = 0;
		isPrime[1] = 0;
		for(int i = 2; i*i<= n; i++)
		{
			if(isPrime[i])
			{
				for(int j = i; i*j <= n; j++)
				{
					if(isPrime[i*j]==1)
					{
						smallestPrimeFactor[i*j] = i;
						isPrime[i*j] = 0;	
					}
				}
			}
		}
		

		for(int i = 0; i<queries.size(); i++)
		{
			int num = queries[i];
			if(smallestPrimeFactor[num] != -1)
			{
				while(smallestPrimeFactor[num] != -1)
				{
					cout<<smallestPrimeFactor[num]<<" ";
					num /= smallestPrimeFactor[num];
				}
			}

			if(num != 1)
				cout<<num;
			cout<<endl;
		}
	}


	// Counting total Divisors of Factor
	void PrimeFactorizationTotalCount(int n, vector<int> &queries)
	{	
		vector<int> isPrime(n+1, 1);
		vector<int> smallestPrimeFactor(n+1, -1);
		isPrime[0] = 0;
		isPrime[1] = 0;
		for(int i = 2; i*i <= n; i++)
		{
			if(isPrime[i])
			{
				for(int j = i; i*j <= n; j++)
				{
					if(isPrime[i*j])
					{
						smallestPrimeFactor[i*j] = i;
						isPrime[i*j] = 0;
					}
				}
			}
		}

		
		for(int i = 0; i<queries.size(); i++)
		{
			int ans = 1;
			int num = queries[i];
			int totalCount = 1;
            while(smallestPrimeFactor[num] != -1)
            {
            	int count = 0;
                int smf = smallestPrimeFactor[num];
                while(num % smf == 0)
                {
                    num /= smf;
                    count++;
                }
                totalCount *= (count + 1);
                
            }
            if (num != 1)
                totalCount *= 2;
            cout<<totalCount<<endl;
		}
		
	}
};
int main()
{
	PrimeFactorization obj;
	int N = 72;
	obj.primeFactorizationBruteForce(N);
	obj.primeFactorizationOptimalBruteFoce(N);
	int n1 = 100;
	vector<int> queries{54, 72, 100};
	obj.primeFactorizationSeive(n1,queries);


	vector<int> queries1{6060, 6064};
	
	obj.PrimeFactorizationTotalCount(7000, queries1);


}