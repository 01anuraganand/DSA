#include <iostream>
#include <vector>
using namespace std;
class catalan
{
	public:
		// print catalan sequence i.e. - 1, 1, 2, 5, 14, 42, 132
		void printCatalan(int n)
		{
			vector<int> storeCatalan(n+1);
			storeCatalan[0] = 1;
			storeCatalan[1] = 1;
			for(int i = 2; i<=n; i++)
			{
				for(int j = 0; j <= i-1; j++)
					storeCatalan[i] += storeCatalan[j]*storeCatalan[i-1-j];
			}

			for(int i = 0; i<=n; i++)
				cout<<storeCatalan[i]<< ", ";
			cout<<endl;
		}
};
int main()
{
	catalan obj;
	obj.printCatalan(6);
}