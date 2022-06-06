#include <iostream>
using namespace std;

struct node
{
	int data;
	node * left = NULL;
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

int binaryTreeHeight(node *curr)
{
	if(curr == NULL) return 0;
	
	int l = binaryTreeHeight(curr->left);
	int r = binaryTreeHeight(curr->right);
	
	return 1+max(l,r);
}


int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->left = newNode(9);
	root->right->right->right = newNode(10);
	cout<< binaryTreeHeight(root);
}

