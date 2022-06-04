#include <iostream>
#include <vector>
#include <stack>
#include <utility>// for pair
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
	return (newnode);
}

void preInPost(node * curr)
{
	stack<pair<node *, int>> st;
	st.push({curr,1});
	vector<int> preOrder, inOrder, postOrder;
	if(curr == NULL) return;
	while(!st.empty())
	{
		auto it = st.top();
		st.pop();
		
		//For preorder-> increment by1->push to left of tree
	
		if(it.second == 1)
		{
			preOrder.push_back(it.first->data);
			it.second++;
			st.push(it);
			if(it.first->left != NULL)
				st.push({it.first->left, 1});
		}
		
		// For inorder->increment by1->push to right of tree
		else if (it.second == 2)
		{
			inOrder.push_back(it.first->data);
			it.second++;
			st.push(it);
			if(it.first->right != NULL)
				st.push({it.first->right, 1});
		}
		else
			postOrder.push_back(it.first->data);
		
	}
	
	
	//printing all traversal
	cout<< " PreOrder Traversal:";
	for(int i = 0; i<preOrder.size(); i++)
	{
		cout<<preOrder[i]<< " ";
	}
	
	
	cout<< "\n InOrder Traversal:";
	for(int i = 0; i<inOrder.size(); i++)
	{
		cout<<inOrder[i]<< " ";
	}
	
	cout<< "\n PostOrder Traversal:";
	for(int i = 0; i<postOrder.size(); i++)
	{
		cout<<postOrder[i]<< " ";
	}
	
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
	preInPost(root);
}