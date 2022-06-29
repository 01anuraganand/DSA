#include <iostream>
#include <vector>
using namespace std;

struct node 
{
	int data;
	node *left = NULL;
	node *right = NULL;
};
node *insert(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

bool nodePath(node * root, vector<int> &ds, int x)
{
	if(root == NULL)
		return false;
	ds.push_back(root->data);
	if(root->data == x)
		return true;
	if (nodePath(root->left, ds, x) || nodePath(root->right, ds, x))
		return true;
	ds.pop_back();
	return false;
}
vector<int> rootToNode(node * root, int x)
{
	vector<int> ds;
	if(root == NULL)
		return ds;
	nodePath(root, ds, x);
	return ds;
}


int main()
{
	node * root = insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->left->left = insert(4);
	root->left->right = insert(5);
	root->left->right->left = insert(6);
	root->left->right->right = insert(7);
	int x = 7;
	vector<int> ans = rootToNode(root, x);
	for(auto it: ans)
		cout<< it<< " ";
}