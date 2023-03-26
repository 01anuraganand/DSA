#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
struct node
{
	int data;
	node *left = NULL;
	node *right = NULL;
};

node * newNode(int val)
{
	node *newnode = new node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

node * designTree(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder, int inStart, int inEnd, unordered_map<int, int> inMap)
{
	if(preStart > preEnd || inStart > inEnd) return NULL;
	
	node * root = newNode(preOrder[preStart]);
	int inRoot = inMap[root->data];
	int numsLeft = inRoot - inStart;
	
	root->left = designTree(preOrder, preStart+1, preStart+numsLeft, inOrder, inStart, inRoot-1, inMap);
	root->right = designTree(preOrder, preStart+numsLeft+1, preEnd, inOrder, inRoot+1, inEnd, inMap);
	return root;
}
node *buildTree(vector<int> &preOrder, vector<int> &inOrder)
{
	unordered_map<int, int> inMap;
	for(int i = 0; i<inOrder.size(); i++)
		inMap[inOrder[i]] = i;
	node * root = designTree(preOrder, 0, preOrder.size()-1, inOrder, 0, inOrder.size()-1, inMap);
	return root;
}
int main()
{
	
  vector<int> preOrder{10,20,40,50,30,60};
  vector<int> inOrder{40,20,50,10,60,30};
  node * root = buildTree(preOrder, inOrder);
  
  cout<<"To print level order:"<<endl;
  queue<node*> q;
  q.push(root);
  vector<vector<int>> ans;
  while(!q.empty())
  {
  	int size = q.size();
  	vector<int> level;
  	for(int i = 0; i<size; i++)
  	{
  		node * curr = q.front();
  		q.pop();
  		if(curr->left)
			q.push(curr->left);
		
		if(curr->right)
			q.push(curr->right);
		
		level.push_back(curr->data);
  	}
  	ans.push_back(level);
  }
  
  for(auto vec1: ans)
  {
  	for(auto it: vec1)
  		cout<<it << " ";
  	cout<<endl;
  }
}