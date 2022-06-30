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
	node *newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

node * lowestCommonAncestor(node * root, node * p, node *q)
{
	if(root == NULL || root == p || root == q)
		return root;
	node * left = lowestCommonAncestor(root->left, p, q);
	node * right = lowestCommonAncestor(root->right, p, q);
	
	if(left == NULL)
		return right;
	else if (right == NULL)
		return left;
	else
		return root;
}
int main()
{
	node *p, *q;
	node * root = insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->right->left = insert(4);
	p  = root->right->left->left = insert(8);
	root->right->right = insert(5);
	root->right->right->left = insert(6);
	q = root->right->right->right = insert(7);
	
	node * ans = lowestCommonAncestor(root, p, q);
	cout<< ans->data<<endl;
	
}