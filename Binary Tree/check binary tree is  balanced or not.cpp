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
	if(l == -1) return -1;
	int r = binaryTreeHeight(curr->right);
	if(r == -1) return -1;
	
	if(abs(l-r)>1) return -1;
	return 1+max(l,r);
}

bool balanced(node * curr)
{
	if(binaryTreeHeight(curr) != -1) return true;
	else false;
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
	cout<< balanced(root)<<endl;
	
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout<<balanced(root)<<endl;
}

