#include <iostream>
#include <string>
using namespace std;

bool palindromeby2var(string str, int l, int r)
{
	if (str[l] != str[r])
		return false;
	palindromeby2var(str, l+1, r-1);
	return true;
}

bool palindrome(string str, int i, int n)
{	
	if (str[i] != str[n-i-1])
		return false;
	palindrome(str, i+1, n);
	return true;
}

int main()
{
	string str;
	str = "naman";
	cout<<palindromeby2var(str, 0, str.length()-1);
	cout<<endl;
	cout<<palindrome(str, 0, str.length());
	
	return 0;
}