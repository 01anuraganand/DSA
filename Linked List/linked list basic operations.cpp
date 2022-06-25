#include <iostream>
using namespace std;

struct node 
{
	int data;
	node * next =NULL;
};

node * insert(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}
// insert at begning if head exists;
node * insertAtBeg(node * head, int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->next = head;
	head = newnode;
	return head;
}

node * insertAtMid(node * head, int val)
{
	if (head == NULL)
		return head;
	node * temp = head;
	int listLen = 0, count = 0;
	while(temp != NULL)
	{
		listLen++;
		temp = temp->next;
	}
	int mid = listLen/2;
	temp = head;
	while(temp != NULL)
	{
		if(count == mid-1)
		{
			node *newnode = new node();
			newnode->data = val;
			newnode->next = temp->next;
			temp->next = newnode;
		}
		count++;
		temp = temp->next;
	}
	return head;
}

node * deleteAtBeg(node * head)
{
	if (head == NULL)
		return head;
	head = head->next;
	return head;
}

node * deleteAtEnd(node *head)
{
	node * temp = head;
	if(temp == NULL)
		return temp;
	while(temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	return head;
}

node * GetMidElement(node *head)
{
	node * slow = head;
	node * fast = head;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<< slow->data<<endl;
	return head;
}

node * deleteAtMid(node * head)
{
	if(head == NULL)
		return NULL;
	int listLen = 0, count = 0;
	node * temp = head;
	while(temp != NULL)
	{
		temp = temp->next;
		listLen++;
	}
	int mid = listLen/2;
	temp = head;
	while(temp != NULL)
	{
		if(count == mid-1)
		{
			temp->next = temp->next->next;
		}
		count++;
		temp = temp->next;
	}
	return head;
}

void traverse(node * root)
{
	if (root == NULL) return ;
	while(root!= NULL)
	{
		cout<< root->data << " ";
		root = root->next;
	}
	cout<<endl;
}

int main()
{
	node * root = insert(1);
	root->next = insert(2);
	root->next->next = insert(3);
	root->next->next->next = insert(4);
	root->next->next->next->next = insert(5);
	root = insertAtBeg(root, 7);
	traverse(root);// printing from root
	
	root = insertAtBeg(root, 8);
	root = insertAtBeg(root, 9);
	traverse(root);
	root = deleteAtBeg(root);
	traverse(root);
	
	root = deleteAtEnd(root);
	traverse(root);
	root = deleteAtEnd(root);
	traverse(root);
	
	root = GetMidElement(root);
	traverse(root);
	
	root = deleteAtMid(root);
	traverse(root);
	
	root = insertAtMid(root, 1);
	traverse(root);
	
}