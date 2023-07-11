#include <iostream>
#include <vector>
using namespace std;
class GCD
{
public:
	// Technique : 1 <= GCD <= min(a,b) 
	int gcdBruteForce(int a, int b)
	{
		int gcd;
		for(int i = 1; i<=min(a, b); i++)
		{
			if(a%i == 0 && b%i == 0)
				gcd = i;
		}
		return gcd;
	}

	// Technique : its brute force approach of division method TC : O(min(a ,b))
	int gcdNaive(int a, int b)
	{
		while(a != b)
		{
			if(a > b)
				a -= b;
			else
				b -= a;
		}
		return a;
	}

	// Technique : Division Method Euclidean Concept TC : O(log(max(a, b)))
	int euclideanGcd(int a, int b)
	{
		int mxVal = max(a, b);
		int mnVal = min(a, b);
		while(mxVal % mnVal != 0)
		{
			int temp = mnVal;
			mnVal = mxVal % mnVal;
			mxVal = temp;
		}
		return mnVal;
	}

	// Task1 : Return the gcd of element present in array TC : O(log(N*max(nums[i])))
	int gcdArray(vector<int> &nums)
	{
		int n = nums.size();
		int gcd = euclideanGcd(nums[0], nums[1]);
		for(int i = 2; i<n; i++)
			gcd = euclideanGcd(gcd, nums[i]);
		return gcd;
	}

};

int main()
{
	GCD obj;
	int a = 18, b = 12;
	vector<int> nums{12, 18, 36};
	cout<<obj.gcdBruteForce(a, b)<<endl;
	cout<<obj.gcdNaive(a, b)<<endl;
	cout<<obj.euclideanGcd(a, b)<<endl;
	cout<<obj.gcdArray(nums)<<endl;
}