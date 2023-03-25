#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct node
{
	int data;
	node *left = NULL;
	node *right = NULL;
};

node *newNode(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void markParents(node *root, unordered_map<node*, node*> &parent_track, node * target)
{
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node * curr = q.front();
		q.pop();
		if(curr->left!= NULL)
		{
			parent_track[curr->left] = curr;
			q.push(curr->left);
		}
		
		if(curr->right != NULL)
		{
			parent_track[curr->right] = curr;
			q.push(curr->right);
		}
	}
}

vector<int> distanceK(node *root, node *target, int k)
{
	unordered_map<node *, node*> parent_track;
	markParents(root, parent_track, target);
	
	unordered_map<node *, bool> visited;
	queue<node *> q;
	q.push(target);
	visited[target] = true;
	int curr_level = 0;
	while(!q.empty())
	{
		int size = q.size();
		if(curr_level++ == k) break;
		for(int i = 0; i<size; i++)
		{
			node * curr = q.front();
			q.pop();
			
			if(curr->left && !visited[curr->left])
			{
				q.push(curr->left);
				visited[curr->left] = true;
			}
			
			if(curr->right && !visited[curr->right])
			{
				q.push(curr->right);
				visited[curr->right] = true;
			}
			
			if(parent_track[curr] && !visited[parent_track[curr]])
			{
				q.push(parent_track[curr]);
				visited[parent_track[curr]] = true;
			}
		}
	}
	vector<int> ans;
	while(!q.empty())
	{
		node * curr = q.front(); 
		q.pop();
		ans.push_back(curr->data);
	}
	return ans;
}

int main()
{
	node * root = newNode(3);
	node * target = root->left = newNode(5);
	root->right = newNode(1);
	root->left->left = newNode(6);
	root->left->right = newNode(2);
	root->right->left = newNode(0);
	root->right->right = newNode(8);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	
	vector<int> ans = distanceK(root, target, 2);
	cout<<"All Nodes Distance K in Binary Tree are:"<<endl;
	for(auto it: ans)
		cout<<it << " ";
}