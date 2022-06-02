#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int data;
	node * left = NULL;
	node * right = NULL;
};

struct node * newNode(int val)
{
	node * newnode = (struct node * ) malloc(sizeof(struct node));
	newnode->data = val;
	newnode->right = NULL;
	newnode->left = NULL;
	return (newnode);
};

void preOrderTrav(node * curr, vector<int> &preOrder)
{
	if (curr == NULL)
		return;
	preOrder.push_back(curr->data);
	preOrderTrav(curr->left, preOrder);
	preOrderTrav(curr->right, preOrder);
}

void inOrderTrav(node * curr, vector<int> & inOrder)
{
	if(curr == NULL)
		return;

	inOrderTrav(curr->left, inOrder);
	inOrder.push_back(curr->data);
	inOrderTrav(curr->right, inOrder);
}

void postOrderTrav(node *curr, vector<int> &postOrder)
{
	if (curr == NULL)
		return;
	postOrderTrav(curr->left, postOrder);
	postOrderTrav(curr->right, postOrder);
	postOrder.push_back(curr->data);
}




int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->right->left = newNode(8);
	root->right->right->left = newNode(9);
	root->right->right->right = newNode(10);
	
	vector<int> preOrder, inOrder, postOrder;
	
	preOrderTrav(root, preOrder);
	cout<< " PreOrder Traversal:";
	
	for(int i = 0; i<preOrder.size(); i++)
	{
		cout<<preOrder[i]<< " ";
	}
	
	
	cout<< "\nInorder Traversal:";
	inOrderTrav(root, inOrder);
	for(int i = 0; i<inOrder.size(); i++)
	{
		cout<<inOrder[i]<< " ";
	}
	
	
	cout<<"\n Postorder Traversal:";
	postOrderTrav(root, postOrder);
	for(int i = 0; i<postOrder.size(); i++)
	{
		cout<<postOrder[i]<< " ";
	}
}