#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node
{
	Node *links[26];
	bool flag = false;
	
	bool conatainsKey(char ch){
		return (links[ch - 'a'] != NULL);
	}
	
	void put(char ch, Node * node){
		links[ch - 'a'] = node;
	}
	
	Node *get(char ch){
		return links[ch - 'a'];
	}

	void setEnd(){
		flag = true;
	}
	
	bool isEnd(){
		return flag;
	}
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
	
	void insert(string &word)
	{
		Node * node = root;
		for(int i = 0; i<word.size(); i++)
		{
			if(!node->conatainsKey(word[i]))
			{
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}
	
	bool checkIfPrefixExists(string &word)
	{
		bool flag = true;
		Node * node = root;
		for(int i = 0; i<word.size(); i++)
		{
			if(node->conatainsKey(word[i]))
			{
				node = node->get(word[i]);
				flag = flag && node->isEnd();
			}	
			else
				return false;
		}
		return flag;
	}
};

string completeString(int n, vector<string> &words)
{
	Trie *trie = new Trie();
	for(auto word : words)
		trie->insert(word);
	string longest = "";
	for(auto &word : words)
	{
		if(trie->checkIfPrefixExists(word))
		{
			if(word.size() > longest.size())
				longest = word;
			else if(word.size() == longest.size() && word < longest)
				longest = word;
		}
	}
	
	if(longest == "") return "None";
	return longest;
}


int main()
{
	int n = 6;
	vector<string> value = {"n", "ni","nin", "ninj", "ninja", "ninga"};
	cout<<completeString(n, value);
}