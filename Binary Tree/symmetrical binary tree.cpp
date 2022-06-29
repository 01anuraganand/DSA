#include <iostream>
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

bool isSymmetric(node * left, node * right)
{
	if (left == NULL || right == NULL)
		return left == right;
	if(left->data != right->data) return false;
	
	return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

bool isSymmetricCall(node * root)
{
	return root == NULL || isSymmetric(root->left, root->right);
}

int main()
{
	node * root = insert(1);
	root->left = insert(2);
	root->right = insert(2);
	root->left->left = insert(3);
	root->right->right = insert(3);
	
	cout<< isSymmetricCall(root)<<endl;
	
	root->left->right = insert(4);
	cout<< isSymmetricCall(root);
		
}