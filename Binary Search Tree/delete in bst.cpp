#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct node
{
	int data;
	node * left = NULL;
	node * right = NULL;
	node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};
//BST Insertion start here
node * insertBST(node * root, int val)
{
	node * cur = root;
	if (root == NULL) return new node(val);
	while(true)
	{
		if(cur->data <= val)
		{
			if(cur->right != NULL) cur = cur->right;
			else {cur->right = new node(val); break;}
		}
		else
		{
			if(cur->left != NULL) cur = cur->left;
			else {cur->left = new node(val);break;}
		}
	}
	return root;
	
}

//BST insertion end here

//BST deletion start here

node *findLastRight(node * root)
{
	if(root->right == NULL) return root;
	return findLastRight(root->right);
}

node * setChild(node * root)
{
	if(root->left == NULL)
		return root->right;
	else if(root->right == NULL)
		return root->left;
	node * rightChild = root->right;
	node * lastRight = findLastRight(root->left);
	lastRight->right = rightChild;
	return root->left;
}

node * deleteBST(node * root, int key)
{
	if (root == NULL)
		return root;
	if(root->data == key)
		return setChild(root);
	node * dummy = root;
	while(root != NULL)
	{
		if(root->data < key)
		{
			if(root->right != NULL && root->right->data == key)
				{root->right = setChild(root->right);break;}
			else
				root = root->right;	
		}
		else
		{
			if(root->left != NULL && root->left->data == key)
				{root->left = setChild(root->left); break;}
			else
				root = root->left;
		}
		
	}
	return dummy;
}

//BST deletion ends here

// InOrder Traversal start here
void inOrderTrav(node * root, vector<int> &ans)
{
	stack<node *> st;
	while(true)
	{
		if(root != NULL)
			{
				st.push(root);
				root = root->left;
			}
		else
		{
			if(st.empty()) break;
			root = st.top();
			ans.push_back(root->data);
			st.pop();
			
			root = root->right;
		}
	}
	
	
}

int main()
{
	node * root = NULL;
	root = insertBST(root, 9);
	insertBST(root, 8);
	insertBST(root, 12);
	insertBST(root, 5);
	insertBST(root, 10);
	insertBST(root, 13);
	insertBST(root, 3);
	insertBST(root, 7);
	insertBST(root, 11);
	insertBST(root, 2);
	insertBST(root, 4);
	insertBST(root, 6);
	insertBST(root, 8);
	insertBST(root, 1);
	
	vector<int> ans;
	inOrderTrav(root, ans);
	for(auto it: ans)
		cout<< it <<  " ";
	cout<<endl;
	root = deleteBST(root, 5);
	vector<int> delans;
	inOrderTrav(root, delans);
	for(auto it: delans)
		cout<< it <<  " ";
}