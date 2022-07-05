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

node * searchBST(node * root, int key)
{
	while(root != NULL && root->data!= key)
	{
		root = root->data < key? root->right : root->left;
	}
	return root;	
}


int main()
{
	
	node *root = newNode(8);
	root -> left = newNode(5);
  	root -> left -> left = newNode(4);
  	root -> left -> right = newNode(7);
  	root -> left -> right -> left = newNode(6);
  	root -> right = newNode(12);
  	root -> right -> left = newNode(10);
  	root -> right -> right = newNode(14);
  	root -> right -> right ->left = newNode(13);
  	
  	node * found = searchBST(root, 10);
  	cout<< &found<<endl;
  	if(found != NULL) cout<< " found.";
  	else cout<< "not found";
  	
}