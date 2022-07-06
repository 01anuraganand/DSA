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

int floorBST(node * root, int key)
{
	int floor = -1;
	while(root)
	{
		if(root->data == key)
			return root->data;
		if(key>root->data)
		{
			floor = root->data;
			root = root->right;
		}
		else
			root = root->left;
	}
	return floor;
}

int main()
{
	node * root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(15);
	root->left->left = newNode(2);
	root->left->right = newNode(8);
	root->right->left = newNode(13);
	root->right->right = newNode(17);
	root->left->right->left = newNode(6);
	cout<<floorBST(root, 7);
}