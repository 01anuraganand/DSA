#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
struct node
{
	int data;
	node * left = NULL;
	node * right = NULL;
};
node * newNode(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

vector<int> bottomView(node * root)
{	
	vector<int> ans;
	if (root == NULL) return ans;
	map<int, int> m;
	queue<pair<node*, int>> q;
	q.push({root, 0});
	while(!q.empty())
	{
		auto it = q.front();
		q.pop();
		node *temp = it.first;
		int line = it.second;
		m[line] = temp->data;
		if(temp->left != NULL)
			q.push({temp->left, line-1});
		if(temp->right != NULL)
			q.push({temp->right, line+1});
	}
	for(auto it: m)
		ans.push_back(it.second);
}
int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);
	root->right->right = newNode(7);
	vector<int> ans = bottomView(root);
	for(auto it: ans)
		cout<< it<< " ";
	
}