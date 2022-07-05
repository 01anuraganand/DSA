#include <iostream>
#include <vector>
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
void leftView(node * root, int level, vector<int> &ans)
{
	if(root == NULL) return;
	if(ans.size() == level) ans.push_back(root->data);
	leftView(root->left, level+1, ans);
	leftView(root->right, level+1, ans);
}


int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->right->left = newNode(10);
	vector<int> ans;
	leftView(root, 0, ans);
	for(auto it: ans)
		cout<< it << " ";
	
}