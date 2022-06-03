#include <iostream>
#include <queue>
#include <vector>
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
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

vector<vector<int>> levelOrder(node * curr)
{
	vector<vector<int>> ans;
	queue<node *> q;
	if(curr == NULL) return ans;
	q.push(curr);
	while(!q.empty())
	{
		int size = q.size();
		vector<int> level;
		for(int i = 0; i<size; i++)
		{
			node * node = q.front();
			q.pop();
			if(node->left != NULL)
				q.push(node->left);
			if(node->right != NULL)
				q.push(node->right);
			level.push_back(node->data);
		}
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
	
	vector<vector<int>> ans = levelOrder(root);
	for(auto vec1:ans)
	{
		cout<<endl;
		for(auto it: vec1)
			cout<< it << " ";
	}
	
}