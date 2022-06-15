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
	node * newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

bool isLeaveNode(node * root)
{
	return !root->left && !root->right;
}

void addLeftBoundary(node * root, vector<int> &res)
{
	node * curr = root->left;
	while(curr)
	{
		if(!isLeaveNode(curr)) res.push_back(curr->data);
		if(curr->left != NULL)
			curr = curr->left;
		else
			curr = curr->right;
	}
}

void addRightBoundary(node *root, vector<int> &res)
{
	node * curr = root->right;
	vector<int> temp;
	while(curr)
	{
		if(!isLeaveNode(curr))  temp.push_back(curr->data);
		if(curr->right != NULL)
			curr = curr->right;
		else
			curr = curr->left;
	}
	for(int i = temp.size()-1; i>=0; i--)
	{
		res.push_back(temp[i]);
	}
}

void addLeaves(node *root, vector<int> &res)
{
	if(isLeaveNode(root))
	{
		res.push_back(root->data);
		return;
	}
	if(root->left != NULL) addLeaves(root->left, res);
	if(root->right != NULL) addLeaves(root->right, res);
}

vector<int> printAntiClockBoundary(node * root)
{
	vector<int> res;
	if(root == NULL)
		return res;
	if(!isLeaveNode(root)) res.push_back(root->data);
	addLeftBoundary(root, res);
	addLeaves(root, res);
	addRightBoundary(root, res);
	return res;
	
}

int main()
{
	node * root = newNode(1);
	root -> left = newNode(2);
	root -> left -> left = newNode(3);
	root -> left -> left -> right = newNode(4);
	root -> left -> left -> right -> left = newNode(5);
	root -> left -> left -> right -> right = newNode(6);
	root -> right = newNode(7);
	root -> right -> right = newNode(8);
	root -> right -> right -> left = newNode(9);
	root -> right -> right -> left -> left = newNode(10);
	root -> right -> right -> left -> right = newNode(11);

	vector < int > AntiClockBoundary = printAntiClockBoundary(root);		
	for(auto it: AntiClockBoundary)
	{
		cout<<it<< " ";
	}
	
}