#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	Node * links[26];
	int cntEndWith = 0;
	int cntPrefix = 0;
	
	bool conatainsKey(char ch){
		return (links[ch - 'a'] != NULL);
	}
	
	Node *get(char ch){
		return links[ch - 'a'];
	}
	
	void put(char ch, Node *node){
		links[ch - 'a'] = node;
	}
	
	void increaseEnd(){
		cntEndWith++;
	}
	void increasePrefix(){
		cntPrefix++;
	}
	
	void deleteEnd(){
		cntEndWith--;
	}
	
	void reducePrefix(){
		cntPrefix--;
	}
	
	int getEnd(){
		return cntEndWith;
	}
	
	int getPrefix(){
		return cntPrefix;
	}
};

class Trie
{
private:
	Node * root;
public:
	Trie(){
		root = new Node();
	}
	
	void insert(string &word)
	{
		Node * node = root;
		for(int i = 0; i<word.size(); i++)
		{
			if(!node->conatainsKey(word[i]))
				node->put(word[i], new Node());
			
			node = node->get(word[i]);
			node->increasePrefix();
		}
		node->increaseEnd();
	}
	
	int countWordsEqualTo(string &word)
	{
		Node *node = root;
		for(int i = 0; i<word.size(); i++)
		{
			
			if(node->conatainsKey(word[i]))
				node = node->get(word[i]);
			else
				return 0;
		}
		return node->getEnd();
	}
	
	int countWordsStartWith(string &word)
	{
		Node * node = root;
		for(int i = 0; i<word.size(); i++)
		{
			if(node->conatainsKey(word[i]))
				node = node->get(word[i]);
			else
				return 0;
		}
		return node->getPrefix();
	}
	
	void erase(string &word)
	{
		Node * node = root;
		for(int i = 0; i<word.size(); i++)
		{
			if(node->conatainsKey(word[i]))
			{
				node = node->get(word[i]);
				node->reducePrefix();
			}
			else
				return;
		}
		node->deleteEnd();
	}
	
};

int main()
{
	int n = 8;
	vector<int> type{1, 1, 1, 1, 2, 3, 4, 2};
	vector<string> value{"apple", "apple", "apps", "apps","apple", "app", "apps", "apps"};
	Trie trie;
	for(int i = 0; i<n; i++)
	{
		if(type[i] == 1)
			trie.insert(value[i]);
		else if(type[i] == 2)
			cout<<"Counts word equal to :"<<trie.countWordsEqualTo(value[i])<<endl;
		else if(type[i] == 3)
			cout<<"Counts the words start with:"<<trie.countWordsStartWith(value[i])<<endl;
		else
			trie.erase(value[i]);
	}
	
}