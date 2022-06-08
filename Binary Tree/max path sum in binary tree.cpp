#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left = NULL;
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

int maxpathsum(node * curr, int &maxsum)
{
	if(curr == NULL)
		return 0;
	int l = max(0,maxpathsum(curr->left, maxsum));
	int r = max(0,maxpathsum(curr->right, maxsum));
	
	maxsum = max(maxsum, l+r+ curr->data);
	
	return max(l, r)+curr->data;
}


int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->left->right = newNode(5);
	root->left->right->left = newNode(10);
	root->left->right->left->right = newNode(11);
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->left = newNode(9);
	root->right->right->right = newNode(10);
	int maxsum = INT_MIN;
	maxpathsum(root, maxsum);
	cout<<maxsum;
}