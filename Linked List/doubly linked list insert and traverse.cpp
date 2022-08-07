#include <iostream>
using namespace std;

struct node
{
	int data;
	node * next = NULL;
	node * prev = NULL;
};

void push_front(node ** head, int val)
{
	node * newnode = new node();
	newnode->data = val;
	newnode->next = *head;
	newnode->prev = NULL;
	if(*head != NULL)
		(*head)->prev = newnode;
	*head = newnode;	
}



int main()
{
	node * head = NULL;
	push_front(&head, 1);
	push_front(&head, 2);
	push_front(&head, 3);
	push_front(&head, 4);
	push_front(&head, 5);
	push_front(&head, 6);
	push_front(&head, 7);
	
	node *last;
	while(head != NULL)
		{
			cout<< head->data<< " ";
			last = head;
			head = head->next;
		}
	cout<< endl;
	while(last != NULL)
	{
		cout<< last->data<<" ";
		last = last->prev;
	}
}