#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string sentenence = "We are  demonstrating sstream.";
	istringstream iss(sentenence);
	string word;
	int i = 0;
	while(iss >> word)
	{
		cout<< i << " ";
		cout<<word<<endl;
		i +=  word.size();
	
	}
}