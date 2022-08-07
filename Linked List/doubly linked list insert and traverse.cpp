#include <iostream>
using namespace std;

struct node
{
	int data;
	node * next = NULL;
	node * prev = NULL;
};

void insertAtBeg(node ** head, int val)
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
	insertAtBeg(&head, 1);
	insertAtBeg(&head, 2);
	insertAtBeg(&head, 3);
	insertAtBeg(&head, 4);
	insertAtBeg(&head, 5);
	insertAtBeg(&head, 6);
	insertAtBeg(&head, 7);
	
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