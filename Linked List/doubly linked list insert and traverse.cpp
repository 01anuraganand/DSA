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

void push_back(node **head, int val)
{
	node * temp = *head;
	node * newnode = new node();
	newnode->data = val;
	if(*head == NULL)
	{
		newnode->prev = NULL;	
		*head = newnode;
		return;
	}
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
	newnode->prev = temp;
	newnode->next = NULL;
}

//insert after previous given node
void insertAt(node * prev, int val)
{
	if(prev == NULL)
	{
		cout<<"Given node is NULL. can't inserted."<<endl;
		return ;
	}
	
	node * newnode = new node();
	newnode->data = val;
	newnode->next = prev->next;
	prev->next = newnode;
	newnode->prev = prev;
	
	if(newnode->next != NULL)
		newnode->next->prev = newnode;	
}

int main()
{
	node * head = NULL;
	insertAt(head, 19);
	push_back(&head, 9);
	push_front(&head, 1);
	push_front(&head, 2);
	push_front(&head, 3);
	push_front(&head, 4);
	push_front(&head, 5);
	push_front(&head, 6);
	push_front(&head, 7);
	push_back(&head, 10);
	insertAt(head, 19);
	
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