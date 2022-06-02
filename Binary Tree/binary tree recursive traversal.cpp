#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node * left = NULL;
	Node *right = NULL;
};

struct Node * insert(int val)
{
	Node * newnode = (struct Node * ) malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->right = NULL;
	newnode->left = NULL;
};

void inorder(Node * root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<< " ";
	inorder(root->right);
}

void preproder(Node * root)
{
	if(root == NULL)
		return;
	cout<<root->data << " ";
	preproder(root->left);
	preproder(root->right);
}

void postoreder(Node *root)
{
	if (root == NULL)
		return;
	postoreder(root->left);
	postoreder(root->right);
	cout<<root->data<< " ";
}




int main()
{
	Node * root = NULL;
	root = insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->left->left = insert(4);
	root->left->right = insert(5);
	root->right->left = insert(6);
	root->right->right = insert(7);
	root->left->right->left = insert(8);
	root->right->right->left = insert(9);
	root->right->right->right = insert(10);
	
	cout<< "Inorder Traversal:"<<endl;
	inorder(root);
	
	cout<< "\nPreorder Traversal:"<<endl;
	preproder(root);
	
	cout<<"\n Postorder Traversal:"<<endl;
	postoreder(root);
}