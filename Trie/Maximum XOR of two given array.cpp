#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	Node * links[2];
	
	bool conatainsKey(int bit)
	{
		return (links[bit] != NULL);
	}
	
	Node *get(int bit)
	{
		return links[bit];
	}
	
	void put(int bit, Node * node)
	{
		links[bit] = node;
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
		
	void insert(int number)
	{
		Node * node = root;
		for(int i = 31; i>=0; i--)
		{
			int bit = (number >> i) & 1;
			if(!node->conatainsKey(bit))
				node->put(bit, new Node());
			node = node->get(bit);
		}
		
	}
	
	int getMax(int number)
	{
		Node * node = root;
		int maxNumber = 0;
		for(int i = 31; i>= 0; i--)
		{
			int bit = (number >> i) &1;
			if(node->conatainsKey(!bit))
			{
				maxNumber = maxNumber | (1<<i);
				node = node->get(!bit);
			}
			else
				node = node->get(bit);
		}
		return maxNumber;
	}
};

int maxXor(vector<int> &nums1, vector<int> &nums2)
{
	Trie trie;
	for(int i = 0; i<nums1.size(); i++)
		trie.insert(nums1[i]);
	
	int mx = 0;
	for(int i = 0; i<nums2.size(); i++)
		mx = max(mx, trie.getMax(nums2[i]));
	return mx;
}

int main()
{
	vector<int> nums1{6, 8};
	vector<int> nums2{7, 8, 2};
	
	cout<<"Max XOR of two array :"<<maxXor(nums1, nums2)<<endl;
	
}