#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * next = NULL;
};

node * insert(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->next = NULL;
}

void traverse(node * root)
{
	if (root == NULL)
		return;
	while(root != NULL)
		{
			cout<< root->data<<endl;
			root = root->next;
		}
	
}

void insertAt(node * head, int n, int val)
{
	if (head == NULL)
		return;
	int count = 0;
	while(head != NULL)
	{
		count++;
		if(count == n-1)
		{
			node *newnode =new node();
			newnode->data = val;
			newnode->next = head->next;
			head->next = newnode;
		}
		head = head->next;
	}
	
}

void deleteAt(node * head, int n)
{
	if (head == NULL)
		return;
	int count = 0;
	while(head != NULL)
	{
		count++;
		if(count == n-1)
		{
			node *temp = head;
			head->next = temp->next->next;
		}
		head = head->next;
	}
}


void removeNfromLast(node * head, int n)
{
	if (head == NULL)
		return ;
	int len = 0;
	node * p = head;
	while(p != NULL)
	{
		len++;
		p = p->next;
	}
	int count = 0;
	while(head != NULL)
	{
		count++;
		if(count == len-n)
		{
			node *temp = head;
			head->next = temp->next->next;
		}
		head = head->next;
	}
}



int main()
{
	node * root = insert(1);
	root->next = insert(2);
	root->next->next = insert(3);
	root->next->next->next = insert(4);
	root->next->next->next->next = insert(5);
	traverse(root);
	cout<<endl;
	
	insertAt(root, 4, 89);
	traverse(root);
	cout<<endl;
	
	deleteAt(root, 4);
	traverse(root);
	
	
	cout<<endl;
	removeNfromLast(root, 3);
	traverse(root);
	
	
	
}