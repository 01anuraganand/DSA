#include <iostream>
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
		node * left = NULL;
		node * right = NULL;
	}
};
node * insertBST(node * root, int val)
{
	if (root == NULL) return new node(val);
	node * cur = root;
	while(true)
	{
		if(cur->data<=val)
			{
				if(cur->right != NULL) cur = cur->right;
				else
					{cur->right = new node(val); break;}
			}
		else
			{
				if(cur->left != NULL) cur = cur->left;
				else
					{cur->left = new node(val); break;}
			}
			
	}
	return root;
}

void inOrderTrav(node * root, vector<int> & ans)
{
	if (root == NULL)
		return;
	inOrderTrav(root->left, ans);
	ans.push_back(root->data);
	inOrderTrav(root->right, ans);
}
int main()
{
	node * root = NULL;
	cout<< "Enter value to insert. type -1 to exit:";
	while(true)
	{
		
		int val; cin>> val;
		if(val == -1)
			break;
		else
			root = insertBST(root, val);
		
	}
	vector<int> ans;
	inOrderTrav(root, ans);
	cout<<endl;
	for(auto it: ans)
		cout<< it<< " ";
}


