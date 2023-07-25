/*
We have been given ‘N’ boys and ‘M’ girls and we need to choose a group containing exactly ‘T’ people having no less than 4 boys and 1 girl. 
Print the number of distinct combinations of groups that are possible. 4<=N<=30 & 1<=M<=30
*/
#include <iostream>
#include <vector>
using namespace std;
class PascalTraingle
{
public:
	vector<vector<long long int>> popultatePascalTriangle(int n, int m)
	{
		vector<vector<long long int>> pascal(n, vector<long long int> (m, 0));
		
		
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<= i; j++)
			{
				if(j == 0 || i == j)
					pascal[i][j] = 1;
				else
					pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
			}
		}
		return pascal;
	}

	long long int solution(int boys, int girls, int totalChoose)
	{

		vector<vector<long long int>> pascal = popultatePascalTriangle(61, 61); //Accordingn to question
		long long int ans = pascal[boys+girls][totalChoose];
		
		if (girls >= totalChoose)  ans -= pascal[boys][0]*pascal[girls][totalChoose];
        if (girls >= totalChoose-1)  ans -= pascal[boys][1]*pascal[girls][totalChoose-1];
        if (girls >= totalChoose-2)  ans -= pascal[boys][2]*pascal[girls][totalChoose-2];
        if (girls >= totalChoose-3)  ans -= pascal[boys][3]*pascal[girls][totalChoose-3];
        if (girls >= totalChoose-4)  ans -= pascal[boys][4]*pascal[girls][totalChoose-4];

        return ans;
	}

};
int main()
{
	PascalTraingle obj;
	cout<<obj.solution(30, 30, 5)<<endl;
}