#include <iostream>
#include <string>
using namespace std;
int main()
{
	string text, pattern;
	cout<<"Enter Text:"<<endl;
	cin>>text;
	cout<<"Enter Pattern:" <<endl;
	cin>>pattern;
	int n = text.size();
	int m = pattern.size();
	for(int i = 0; i <= n - m; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(pattern[j] != text[i+j])
			{
				break;
			}
			if(j == m-1)
				cout<<"String match at:"<<i<<endl;
		}
	}
}