#include <bits/stdc++.h>
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

node *mergeTree(node *root1, node * root2)
{
	if (root1 == NULL)
		return root2;
	if(root2 == NULL)
		return root1;
	
	root1->data = root1->data+root2->data;
	
	root1->left = mergeTree(root1->left, root2->left);
	root1->right = mergeTree(root1->right, root2->right);

	return root1;
}
void inOrderTrav(node * curr, vector<int> & inOrder)
{
	if(curr == NULL)
		return;

	inOrderTrav(curr->left, inOrder);
	inOrder.push_back(curr->data);
	inOrderTrav(curr->right, inOrder);
}

int main()
{
	node * root1 = newNode(1);
	root1->left = newNode(3);
	root1->right = newNode(2);
	root1->left->left = newNode(5);
	
	node * root2 = newNode(2);
	root2->left = newNode(1);
	root2->right = newNode(3);
	root2->left->right = newNode(4);
	root2->right->right = newNode(7);
	
	node * trav = mergeTree(root1, root2);
	vector<int> inOrder;
	inOrderTrav(trav, inOrder);
	for(auto it:inOrder)
		cout<< it<<" ";
}