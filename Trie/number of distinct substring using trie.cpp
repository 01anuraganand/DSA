#include <iostream>
using namespace std;

struct Node
{
	Node *links[26];
	bool conatainsKey(char ch)
	{
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch, Node *node)
	{
		links[ch - 'a'] = node;
	}
	
	Node * get(char ch)
	{
		return links[ch - 'a'];
	}
}; 

int countDistinctSubstring(string &word)
{
	int count = 0;
	Node * root = new Node();
	for(int i = 0; i<word.size(); i++)
	{
		Node * node = root;
		for(int j = i; j<word.size(); j++)
		{
			if(!node->conatainsKey(word[j]))
			{
				count++;
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
	}
	return count+1;
}

int main()
{
	string word = "abcd";
	cout<<"Total distinct substrings are:"<<countDistinctSubstring(word)<<endl;
}