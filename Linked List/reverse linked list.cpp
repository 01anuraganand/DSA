#include <iostream>
using namespace std;
//not completed
struct node
{
	int data;
	node *next = NULL;
};
node *insert(int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}

void traverse(node *head)
{
	if (head == NULL)
		return ;
	while(head != NULL)
	{
		cout<< head->data<< " ";
		head = head->next;
	}
}

node *reverseList(node * head)
{
	if (head == NULL)
		return head;
	
	node  *curr = head;
	node *tempnext=NULL, *prev=NULL;
	while(curr!= NULL)
	{
		tempnext = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tempnext;
	}
	head = prev;
	return head;
	
}


int main()
{
	node *root  = insert(1);
	root->next = insert(2);
	root->next->next = insert(3);
	root->next->next->next = insert(4);
	root->next->next->next->next = insert(5);
	traverse(root);
	root = reverseList(root);
	cout<<endl;
	traverse(root);
	
}