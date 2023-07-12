#include <iostream>
#include <math.h>
using namespace std;
class Factor
{
	public:

		// Brute Force approach TC O(N)
		void factorOfNumberBruteForce(int Num)
		{
			for(int i = 1; i<= Num; i++)
				if(Num % i == 0)
					cout<<i << " ";
			cout<<endl;
		}

		/*
		N = 16
		Approach to run the loop by N/2 as next factor is interpreted by Num*2
		1 2 4 8 16 -> see upon dividing 8*2 = 16 which make Num/2 
		Then simply print the Num itself because the factor be never be less or greater than, its always equal
		TC - O(N/2)->O(N)
		*/
		void factorOfNumberHalfNApproach(int Num) 
		{
			for(int i = 1; i<= Num/2; i++)
				if(Num % i == 0)
					cout<<i << " ";
			cout<<Num<<endl;
		}

		/*
		N = 16
		Approach to run the loop by sqrt(N ) as next factor is interpreted by (N/i) i.e - 16/1->16, 16/2->8, 16/4->4
		Which gives the second half sequence
		If that i half give (i*i === Num) -> (4*4 == 16) the only one time print i - i.e - 4

		  		|
		1 	2	4	8	16
		|	|	|	|	 |
		|	|___|___|	 | 	
		|_______|________|
				|			
		TC - sqrt(N)
		*/


		void factorOfNumberOptimal(int Num)
		{
			for(int i = 1; i<=sqrt(Num); i++)
			{
				if(Num % i == 0)
				{
					if(i*i == Num) cout<<i<<" ";
					else
						cout<<i<<" "<<Num/i<<" ";
				}
			}
		}

		// Task1 : Print False if Number of divisor is Even else True
		void task(int Num)
		{
			int midDivsor = sqrt(Num); 
			// checking for perfect number, 
			// if midDivsor is perfect square then (2*midDivsor + 1) element of divisor will be there
			if(midDivsor*midDivsor == Num) cout<<"\nTrue";
			else cout<<"\nFalse";
		}
};
int main()
{
	Factor obj;
	int n = 64;
	obj.factorOfNumberBruteForce(n);
	obj.factorOfNumberHalfNApproach(n);
	obj.factorOfNumberOptimal(n);
	obj.task(n);
}