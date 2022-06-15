#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left = NULL;
	node *right = NULL;
};

node * newNode(int val)
{
	node *newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
void leavesSum(node * root, int &n)
{
	
	if(root == NULL)
		return;
	
	leavesSum(root->left, n);
	leavesSum(root->right, n);
	if(root->left == NULL && root->right == NULL)
		n += root->data;
	
}
int main()
{
	
	node * root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	root->left->left->left = newNode(7);
	root->right->right = newNode(6);
	root->right->right->right = newNode(8);
	int n = 0;
	leavesSum(root, n);
	cout<<n;
	
}