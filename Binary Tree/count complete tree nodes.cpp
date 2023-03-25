#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int data;
	node *left = NULL;
	node *right = NULL;
};

node * newNode(int val)
{
	node *newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int findHeightR(node *temp)
{
	int height = 0;
	while(temp)
	{
		height++;
		temp = temp->left;
	}
	return height;
}

int findHeightL(node * temp)
{
	int height = 0;
	while(temp)
	{
		height++;
		temp = temp->right;
	}
	return height;
}

int countNodes(node * root)
{
	if(root == NULL) return 0;
	
	int lh = findHeightL(root);
	int rh = findHeightR(root);
	
	if(lh == rh) return (1<<lh) -1;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	cout<<"count of complete nodes :"<<countNodes(root)<<endl;
}