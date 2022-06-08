#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left = NULL;
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

bool identicalTree(node *curr1, node *curr2)
{
	if (curr1 == NULL && curr2 == NULL)
		return true;
	else if (curr1 == NULL || curr2 == NULL)
		return false;
	
	return ((curr1->data == curr2->data) && identicalTree(curr1->left, curr2->left ) && identicalTree(curr1->right, curr2->right));
	
}

int main()
{
	node * root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->right->left = newNode(6);
	root1->right->right = newNode(7);
	
	node * root2 = newNode(1);
	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->right->left = newNode(6);
	root2->right->right = newNode(7);
	
	cout<< identicalTree(root1, root2);
	
}