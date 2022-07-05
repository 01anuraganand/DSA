#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	Node *links[26];
	bool flag = false;
	//checking reference trie is present or not;
	bool conatainsKey(char ch)
		{return (links[ch-'a'] != NULL);}
	
	// creating reference trie;
	void put(char ch, Node * node)
		{links[ch-'a'] = node;}
	
	//setting flat to true at the end of word
	void setEnd()
		{flag = true;}
	
	//to get the next node for traversal
	Node *get(char ch)
		{return links[ch -'a'];}
	
	//checking if the word is completed on not;
	bool isEnd()
		{return flag;}
};
class Trie
{
private:
	Node * root;
public:
	Trie()
	{
		root = new Node();
	}
	
	void insert(string word)
	{
		Node * node = root;
		for(int i = 0; i< word.size(); i++)
		{
			if(!node->conatainsKey(word[i]))
			{
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}
	
	
	bool search(string word)
	{
		Node * node = root;
		for(int i = 0; i<word.size(); i++)
		{
			if(!node->conatainsKey(word[i]))
				return false;
			node = node->get(word[i]);
		}
		return (node->isEnd());
	}
	
	bool startsWith(string prefix)
	{
		Node * node = root;
		for(int i = 0; i<prefix.size(); i++)
			{
				if(!node->conatainsKey(prefix[i]))
					return false;
				node = node->get(prefix[i]);
			}
			return true;
	}
	
};

int main()
{
	int n = 5;
	vector<int> type = {1, 1, 2, 3, 2};
	vector<string> value = {"hello", "help","help", "hel", "hel"};
	Trie trie;
	for(int i = 0; i<n; i++)
	{
		if(type[i] == 1)
			trie.insert(value[i]);
		else if(type[i] == 2)
		{
			if(trie.search(value[i]))
				cout<< "true"<< "\n";
			else
				cout<< "false"<< "\n";
			
		}
		else
		{
			if(trie.startsWith(value[i]))
				cout<< "true"<< "\n";
			else
				cout<< "false"<< "\n";
		}
	}
}