#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node
{
	int data;
	struct node * left, * right;
};

struct node * newNode(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

vector<int> preOrderTrav(node *curr)
{
	vector<int> preOrder;
	stack <node *> st;
	
	if (curr == NULL)
		return preOrder;
	st.push(curr);
	
	while(!st.empty())
	{
		node *topNode = st.top();
		
		preOrder.push_back(topNode->data);
		st.pop();
		
		if(topNode->right != NULL)
			st.push(topNode->right);
		if(topNode->left != NULL)
			st.push(topNode->left);
	}
	
	return preOrder;
}


vector<int> inOrderTrav(node *curr)
{
	vector<int> inOrder;
	stack<node *> st;
		
	while(true)
	{
		
		if(curr != NULL)
			{
				st.push(curr);
				curr = curr->left;
			}
		else
			{
				if(st.empty()) break;
				curr = st.top();
				
				inOrder.push_back(curr->data);
				st.pop();
				
				curr = curr->right;	
			}	
	}
	return inOrder;
}



vector<int> postOrderTrav(node *curr)
{
	vector<int> postOrder;
	
	stack<node *> st;
	
	if (curr == NULL)
		return postOrder;
	
	while(curr != NULL || !st.empty())
	{
		if(curr != NULL)
		{
			st.push(curr);
			curr = curr->left;
		}
		else
		{
			node *temp = st.top() -> right;
			if(temp ==  NULL)
			{
				temp = st.top();
				st.pop();
				postOrder.push_back(temp->data);
				while(!st.empty() && temp == st.top()->right)
				{
					temp = st.top();
					st.pop();
					postOrder.push_back(temp->data);
				}
			}
			else
				curr = temp;	
		}
	}
	return postOrder;
}

int main()
{
	node * root = NULL;
	root = newNode(1);
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
	preOrder = preOrderTrav(root);
	cout<< " PreOrder Traversal:";
	for(int i = 0; i<preOrder.size(); i++)
	{
		cout<<preOrder[i]<< " ";
	}
	
	
	inOrder = inOrderTrav(root);
	cout<< "\n InOrder Traversal:";
	for(int i = 0; i<inOrder.size(); i++)
	{
		cout<<inOrder[i]<< " ";
	}
	
	postOrder = postOrderTrav(root);
	cout<< "\n PostOrder Traversal:";
	for(int i = 0; i<postOrder.size(); i++)
	{
		cout<<postOrder[i]<< " ";
	}
}