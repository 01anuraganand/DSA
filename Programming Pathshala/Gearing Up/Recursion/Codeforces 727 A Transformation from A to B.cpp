#include <iostream>
#include <vector>
using namespace std;
bool flag = false;
void solve(long long int a, long long int b, vector<long long int> &ans)
{
	
	if(a == b)
	{	
		flag = true;
		ans.push_back(b);
		return;
	}
	
	if (b<a)
	{
		ans.clear();
		return ;
	}
	
	if(b % 2 == 0)
	{
		solve(a, b/2, ans);
		ans.push_back(b);
	}
	
	else if(b%10 == 1)
	{
		solve(a, b/10, ans);
		ans.push_back(b);
	}	
	
}
int main()
{
	long long int a, b;
	cin>> a >> b;
	vector<long long int> ans;
	
	solve(a, b, ans);
	if(!flag)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		for(auto it: ans)
			cout<<it<<" ";
	}
	
}
