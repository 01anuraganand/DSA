#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
	int data;
	node *left = NULL;
	node *right = NULL;
};

node * newNode(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

vector<vector<int>> zigzagtarversal(node * curr)
{
	vector<vector<int>> ans;
	vector<int> level;
	queue<node *> q;
	
	if( curr == NULL)
		return ans;
	
	q.push(curr);
	bool leftToRight = true;
	while(!q.empty())
	{
		
		int size = q.size();
		vector<int> level(size);
		for(int i = 0; i<size; i++)
		{
			node *node = q.front();
			q.pop();
			
			int index = leftToRight ? i : (size-i-1);
			level[index] = node->data;
			
			if (node->left != NULL) q.push(node->left);
			if(node->right!= NULL) q.push(node->right);
			
						
		}
		leftToRight = !leftToRight;
		ans.push_back(level);
	}
	
	return ans;
}


int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->right->left = newNode(8);
	root->right->right->left = newNode(9);
	root->right->right->right = newNode(10);
	vector<vector<int>> ans = zigzagtarversal(root);
	for(auto vec1: ans)
	{
		cout<<endl;
		for(auto it: vec1)
			cout<< it << " ";
	}
}