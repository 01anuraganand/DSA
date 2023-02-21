//Rabin Karp String Matching Algorithm using Modulus Method
#include <iostream>
#include <string>
#include <vector>
#define TEXT_SIZE 256
using namespace std;
void search(string text, string pattern, int primeNumber)
{
	int N = text.size();
	int M = pattern.size();
	int i, j, hashP = 0, hashT = 0, hash = 1;
	
	for(i = 0; i<M-1; i++)
	{
		hash = (hash * TEXT_SIZE) % primeNumber;
	}
		
	for(i = 0; i<M; i++)
	{
		hashP = (TEXT_SIZE*hashP + pattern[i]) % primeNumber;
		hashT = (TEXT_SIZE*hashT + text[i]) % primeNumber;
	}
	
	for(i = 0; i<= N - M ; i++)
	{
		if(hashP == hashT)
		{
			for(j = 0; j<M; j++)
			{
				if(text[i+j] != pattern[j])
					break;
			}
			if(j == M)
				cout<<"Pattern found at:"<<i<<endl;
		}
		if(i < N - M)
		{
			hashT = (TEXT_SIZE *(hashT - text[i] * hash) + text[i+M]) % primeNumber;
			if(hashT < 0)
				hashT = (hashT+primeNumber);
		}	
	}	
}

int main()
{
	string text, pattern;
	cout<<"Enter the Text:"<<endl;
	cin>> text;
	cout<<"Enter pattern:"<<endl;
	cin>>pattern;
	search(text, pattern, 11)	;
}