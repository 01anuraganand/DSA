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

void changeTree(node *root)
{
	if (root == NULL)
		return ;
	int child = 0;
	if(root->left)
		child += root->left->data;
	if(root->right)
		child += root->right->data;
	if(child>=root->data) root->data = child;
	else
	{
		if(root->left) root->left->data = root->data;
		else if(root->right) root->right->data = root->data;
	}
	
	changeTree(root->left);
	changeTree(root->right);
	int tot = 0;
	if(root->left) tot += root->left->data;
	if(root->right) tot += root->right->data;
	if(root->left || root->right) root->data =tot;
		
}

vector<vector<int>> levelOrder(node * root)
{
	vector<vector<int>> ans;
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		int size = q.size();
		vector<int> level;
		for(int i = 0; i<size; i++)
		{
			auto it = q.front();
			q.pop();
			level.push_back(it->data);
			if(it->left)
				q.push(it->left);
			if(it->right)
				q.push(it->right);
		}
		ans.push_back(level);
	}
	return ans;
}

int main()
{
	node * root = insert(2);
	root->left = insert(35);
	root->right = insert(10);
	root->left->right = insert(3);
	root->left->left = insert(2);
	root->right->left = insert(5);
	root->right->right = insert(2);
	vector<vector<int>> ans = levelOrder(root);
	for(auto vec1: ans)
	{
		cout<< endl;
		for(auto it: vec1)
			cout<< it << " ";
	}
	
	changeTree(root);
	cout<<endl;
	ans = levelOrder(root);
	for(auto vec1: ans)
	{
		cout<< endl;
		for(auto it: vec1)
			cout<< it << " ";
	}
}


