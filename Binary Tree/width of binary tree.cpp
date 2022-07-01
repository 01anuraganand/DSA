#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node *left = NULL;
	node *right = NULL;
};

node * insert(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int widthOfBinaryTree(node *root)
{
	if(!root)
		return 0;
	int ans = 0;
	queue<pair<node *, int>> q;
	q.push({root, 0});
	while(!q.empty())
	{
		int size = q.size();
		int curMin = q.front().second;
		int leftMost, rightMost;
		for(int i = 0; i<size; i++)
		{
			int cur_id = q.front().second - curMin;
			node *tempnode = q.front().first;
			q.pop();
			if(i == 0) leftMost = cur_id;
			if(i == size-1) rightMost = cur_id;
			if(tempnode->left)
				q.push({tempnode->left, cur_id*2+1});
			if(tempnode->right)
				q.push({tempnode->right, cur_id*2+2});
		}
		ans = max(ans, rightMost-leftMost+1);
	}
	return ans;
}

int main()
{
	node * root = insert(5);
	root->left = insert(6);
	root->right = insert(7);
	root->left->left = insert(8);
	root->right->right = insert(9);
	cout<< widthOfBinaryTree(root);
}