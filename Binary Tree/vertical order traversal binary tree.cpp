#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct node
{
	int data;
	node * left = NULL;
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

vector<vector<int>> verticalTraversal(node * root) 
{
	map<int, map<int, multiset<int>>> nodes;
	queue<pair<node*, pair<int, int>>> todo;
	todo.push({root, {0,0}});
	while(!todo.empty())
	{
		auto p = todo.front();
		todo.pop();
		node * temp = p.first;
		
		int x = p.second.first, y = p.second.second;
		nodes[x][y].insert(temp->data);
		if(temp->left)
		{
			todo.push({temp->left,{x-1, y+1}});
		}
		
		if(temp->right)
		{
			todo.push({temp->right, {x+1, y+1}});
		}
	}
	
	vector<vector<int>> ans;
	for(auto p:nodes)
	{
		vector<int> col;
		for(auto q:p.second)
		{
			col.insert(col.end(), q.second.begin(), q.second.end());
		}
		ans.push_back(col);
	}
	return ans;
	
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(10);
  root -> left -> left -> right = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(3);
  root -> right -> left = newNode(9);
  root -> right -> right = newNode(10);

  vector < vector < int > > verticalTrav;
  verticalTrav = verticalTraversal(root);

  cout << "The Vertical Traversal is : " << endl;
  for (auto vertical: verticalTrav) {
    for (auto nodeVal: vertical) {
      cout << nodeVal << " ";
    }
    cout << endl;
  }

}