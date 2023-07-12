#include <iostream>
#include <vector>
using namespace std;
class LCM
{
public:
	// Technique 1 : max(a, b) <= LCM <= a*b
	int LCMBruteForce(int a, int b)
	{
		
		for(int lcm = max(a,b); lcm<a*b; lcm++)
		{
			if(lcm % a == 0 && lcm % b == 0)
				return lcm;
		}
		return a*b;
	}

	// Technique 2 : GCD(a, b)*LCM(a, b) = 1
	int euclideanGcd(int a, int b)
	{
		int mxVal = max(a, b);
		int mnVal = min(a, b);
		if(mnVal == 0) return mxVal;
		while(mxVal % mnVal != 0)
		{
			int temp = mnVal;
			mnVal = mxVal % mnVal;
			mxVal = temp;
		}
		return mnVal;
	}

	int lcmOptimal(int a, int b)
	{
		int mxVal = max(a, b);
		int mnVal = min(a, b);
		int gcd = euclideanGcd(mxVal, mnVal);
		return (a*b)/gcd;
	}

	// ---------------------------------------Inclusion - Exclusion Principle based question -------------------------------

	// Task1 : Find the lcm of array 
	int lcmArray(vector<int> &nums)
	{
		int n = nums.size();
		int lcm = lcmOptimal(nums[0], nums[1]); // lcm of first two number
		for(int i = 2; i<n; i++)
		{
			lcm = (lcm * nums[i])/(euclideanGcd(lcm, nums[i]));
		}
		return lcm;
	}

	// Task 2: Find the count of elements from range 1 to N, which are divisible by A or B (It means it is divisible by atleast A, or atleast B, or by both )
	int countNumberOfElementsDivisible2(int N, int a, int b)
	{
		int countADiv = N/a, countBDiv = N/b;
		/*
			Think in terms of Venn Diagram so only two number are there so 
			N    N       N
			-- + -- - --------
			A    B    lcm(A, B)
		*/

		return (N/a) + (N/b) - (N/lcmOptimal(a, b));
	}

	// Task3 : Task 2 with number which are divisible of A or B or C.
	int countNumberOfElementsDivisible3(int N, vector<int> &nums)
	{
		int size = nums.size();
		/*
			Again think in terms of venn diagram
			 N     N     N         N 		   N             N              N
			--- + --- + --- -  ---------  - --------  -  --------- + ----------------
			 A     B     C     lcm(A, B)    lcm(B, C)    lcm(C, A)   lcm(lcm(A, B), C)
		*/

		// Calculate the Total Divisible by each number i.e (N/nums[i])
		int countCompleteDiv = 0;
		for(int i = 0; i<size; i++) countCompleteDiv += (N / nums[i]);

		// find lcm of next consecutive element , and for last element find with last and first element
		int countLCM = 0;
		
		for(int i = 0; i<size; i++) countLCM += (N/lcmOptimal(nums[i], nums[(i+1)%size]));

		// find the common lcm for all case lcm(lcm(a, b), c)
		int commonLCM = N / lcmArray(nums);
	
		return countCompleteDiv - countLCM + commonLCM;

	}
};
int main()
{
	int a = 12, b = 36;
	vector<int> nums{12, 36, 48};
	LCM obj;
	cout<<obj.LCMBruteForce(a, b)<<endl;
	cout<<obj.lcmOptimal(a, b)<<endl;
	cout<<obj.lcmArray(nums)<<endl;
	cout<<obj.countNumberOfElementsDivisible2(20, 2, 3)<<endl;
	cout<<obj.countNumberOfElementsDivisible3(20, nums= {2, 3, 5})<<endl;
}