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

bool validBST(node * root, int minVal, int maxVal)
{
	if (root == NULL) return true;
	
	if(root->data >= maxVal || root->data <= minVal) return false;
	
	return validBST(root->left, minVal, root->data) && validBST(root->right, root->data, maxVal);
}

bool isValidBST(node * root)
{
	return validBST(root, INT_MIN, INT_MAX);
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
	
	cout<< isValidBST(root)<<endl;
	
	root->left = newNode(18);
	
	cout<< isValidBST(root);
}
