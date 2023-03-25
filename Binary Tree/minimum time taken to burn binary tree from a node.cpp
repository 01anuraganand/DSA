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

node * markParents(node * root, unordered_map<node *, node*> &parent_track, int start)
{
	queue<node *> q;
	q.push(root);
	node * startP;
	while(!q.empty())
	{
		int size = q.size();
		node * curr = q.front();
		if(curr->data == start) startP = curr;
		q.pop();
		if(curr->left)
		{
			parent_track[curr->left] = curr;
			q.push(curr->left);
		}
		
		if(curr->right)
		{
			parent_track[curr->right] = curr;
			q.push(curr->right);
		}
	}
	return startP;
}

int findMaxDistance(unordered_map<node *, node*> &parent_track, node * target)
{
	queue<node*> q;
	unordered_map<node*, bool> visited;
	q.push(target);
	visited[target] = true;
	int time = 0;
	while(!q.empty())
	{
		int size = q.size();
		bool flag = false;
		for(int i = 0; i<size; i++)
		{
			node * curr = q.front();
			q.pop();
			if(curr->left && !visited[curr->left])
			{
				flag = true;
				visited[curr->left] = true;
				q.push(curr->left);
			} 
			
			if(curr->right && !visited[curr->right])
			{
				flag = true;
				visited[curr->right] = true;
				q.push(curr->right);
			}
			
			if(parent_track[curr] && !visited[parent_track[curr]])
			{
				flag =true;
				visited[parent_track[curr]] = true;
				q.push(parent_track[curr]);
			}
		}
		if(flag) time++;
	}
	return time;
}
int timeToBurnTree(node * root, int start)
{
	unordered_map<node*, node *>  parent_track;
	node * targetStart = markParents(root, parent_track, start);
	return  findMaxDistance(parent_track, targetStart);	
}
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->left->left->right = newNode(7);
	
	cout<<"Minimum Time to burn:"<<timeToBurnTree(root, 2)<<endl;
}