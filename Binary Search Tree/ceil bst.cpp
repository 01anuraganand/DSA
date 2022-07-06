#include <iostream>
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

int ceilBST(node * root, int key)
{
	int ceil = -1;
	while(root)
	{
		if(root->data == key)
			return root->data;
		if(key>root->data)
			root = root->right;
		else
		{
			ceil = root->data;
			root = root->left;
		}
	}
	return ceil;
}


int main()
{
	node * root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(13);
	root->left->left = newNode(3);
	root->left->right = newNode(6);
	root->right->left = newNode(11);
	root->right->right = newNode(14);
	root->left->left->left = newNode(2);
	root->left->left->right = newNode(4);
	root->left->right->right = newNode(9);
	cout<<ceilBST(root, 8);
}