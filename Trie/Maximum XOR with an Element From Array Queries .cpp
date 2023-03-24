#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct Node
{
	Node * links[2];
	
	bool conatainsKey(int bit)
	{
		return (links[bit] != NULL);
	}
	
	Node * get(int bit)
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
		Node *node = root;
		
		for(int i = 31; i>= 0; i--)
		{
			int bit = (number >> i) & 1;
			if(!node->conatainsKey(bit))
			{
				node->put(bit, new Node());
			}
			node = node->get(bit);
		}
	}
	
	int getMax(int number)
	{
		Node * node = root;
		int maxNumber = 0;
		for(int i = 31; i>= 0; i--)
		{
			int bit = (number >> i) & 1;
			if(node->conatainsKey(!bit))
			{
				maxNumber = maxNumber | (1 << i);
				node = node->get(!bit);
			}
			else
				node = node->get(bit);
		}
		return maxNumber;
	}
};

vector<int> maxXORQueries(vector<int> &arr, vector<vector<int>> &queries)
{
	sort(arr.begin(), arr.end());
	vector<pair<int, pair<int, int>>> offlineQueries;
	int q = queries.size();
	for(int i = 0; i<q; i++)
		offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
	
	sort(offlineQueries.begin(), offlineQueries.end());
	
	vector<int> ans(q, 0);
	int index = 0;
	int n = arr.size();
	Trie trie;
	for(int i = 0; i<q; i++)
	{
		int ai = offlineQueries[i].first;
		int xi = offlineQueries[i].second.first;
		int qIndex = offlineQueries[i].second.second;
		while(index < n && arr[index] <= ai)
		{
			trie.insert(arr[index]);
			index++;
		}
		
		if(index == 0) ans[qIndex] = -1;
		else
			ans[qIndex] = trie.getMax(xi);
		
	}
	return ans;
}
int main()
{
	vector<int> arr{0, 1, 2, 3, 4, 5};
	vector<vector<int>> queries{{1, 3}, {5, 6}};
	
 	vector<int> ans =  maxXORQueries(arr, queries);
 	cout<<"Max XOR of two array in queries :"<<endl;
 	for(auto it: ans)
 		cout<<it << " ";
}