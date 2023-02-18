#include <iostream>
#include <vector>
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

vector<int> morrisInPOst(node * root, bool inorder = true)
{
	vector<int> inOrder, preOrder;
	node * curr = root;
	while(curr != NULL)
	{
		if(curr->left == NULL)
		{
			inOrder.push_back(curr->data);
			preOrder.push_back(curr->data); 
			curr = curr->right;
		}
		else
		{
			node * aheadRight = curr->left;
			while(aheadRight->right && aheadRight->right != curr)
			{
				aheadRight = aheadRight->right;
			}
			
			if(aheadRight->right == NULL)
			{
				aheadRight->right = curr;
				preOrder.push_back(curr->data);
				curr =  curr->left;
			}
			else
			{
				aheadRight->right = NULL;
				inOrder.push_back(curr->data);
				curr = curr->right;
			}
			
		}
	}
	return inorder ? inOrder : preOrder;
}

int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right = newNode(6);
	
	cout<<"Inorder Traversal:"<<endl;
	vector<int> ans = morrisInPOst(root, true);
	for(auto it : ans)
		cout<< it << " ";
	
	cout<<"\nPreOrder Traversal:"<<endl;
	ans = morrisInPOst(root, false);
	for(auto it : ans)
		cout<< it << " ";
	
}