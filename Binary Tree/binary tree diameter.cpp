#include <iostream>
#include <algorithm>
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

int diameter(node *curr, int &dia)
{
	if(curr == NULL)
		return 0;
	int l = diameter(curr->left, dia);
	int r = diameter(curr->right, dia);
	
	dia = max(dia, l+r);
	
	return 1+max(l,r);
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
	int dia = 0;
	diameter(root, dia);
	cout<<dia;
	
}