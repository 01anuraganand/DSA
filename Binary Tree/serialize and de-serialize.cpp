#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
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

string serialize(node * root)
{
	string s = "";
	if(!root) return s;
	
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node* currnode = q.front();
		q.pop();
		if(currnode == NULL) s.append("#,");
		else s.append(to_string(currnode->data) + ',');
		if(currnode != NULL)
		{
			q.push(currnode->left);
			q.push(currnode->right);
		}
	}
	return s;
}

node * deserialize(string serStr)
{
	if(serStr.size() == 0) return NULL;
	stringstream s(serStr);
	
	string str;
	getline(s, str, ',');
	node * root = newNode(stoi(str));
	
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node * currnode = q.front();
		q.pop();
		getline(s, str, ',');
		if(str == "#") 
			currnode->left = NULL;
		else
		{
			node * leftnode = newNode(stoi(str));
			currnode->left = leftnode;
			q.push(leftnode);	
		}
		
		getline(s, str, ',');
		if(str == "#")
			currnode->left = NULL;
		else
		{
			node * rightnode = newNode(stoi(str));
			currnode->right = rightnode;
			q.push(rightnode);
		}
		
	}
	return root;
}
int main()
{
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	string ser = serialize(root);
	cout<<"Serialize:"<<ser<<endl;
	
	node * root1 = deserialize(ser);
	//Level Order traversal
	vector<vector<int>> ans;
	queue<node*> q;
	q.push(root1);
	while(!q.empty())
	{
		int size = q.size();
		vector<int> level;
		for(int i = 0; i<size; i++)
		{
			node * currnode = q.front();
			q.pop();
			
			if(currnode->left)
				q.push(currnode->left);
			if(currnode->right)
				q.push(currnode->right);
			level.push_back(currnode->data);
		}
		ans.push_back(level);
	}
	
	
	for(auto vec1: ans)
	{
		for(auto it : vec1)
			cout<< it << " ";
		cout<<endl;
	}
}