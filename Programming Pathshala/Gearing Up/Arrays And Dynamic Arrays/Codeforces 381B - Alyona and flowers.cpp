#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main()
{
	int n, m;
	cin>> n >> m;
	vector<int> flowerMoods(n);
	
	for(int i = 0; i< n; i++)
		cin>>flowerMoods[i];
	vector<pair<int, int>> subArrayRange(m);
	for(int i = 0; i<m; i++)
		cin>> subArrayRange[i].first >> subArrayRange[i].second;
	
	// Prefix Sum
	for(int i =1; i<n; i++)
		flowerMoods[i] += flowerMoods[i-1];
	
	int ans = 0;
	for(const auto& [l, r]: subArrayRange)
	{
		
		if(l-1 == 0 && flowerMoods[r-1]>0)
			ans += flowerMoods[r-1];
			
		else if(flowerMoods[r-1] - flowerMoods[l-1-1] >= 0)
			ans += (flowerMoods[r-1]- flowerMoods[l-1-1]);		
	}
	cout<<ans<<endl;
}