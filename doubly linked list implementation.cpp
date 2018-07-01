//doubly linked list implementation
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head;

struct node *getnewnode(int x)
{
	struct node *newnode=new node();
	newnode->data=x;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}

void insertathead(int x)
{
	struct node *newnode= getnewnode(x);
	if(head==NULL)
	{
		head=newnode;
		return ;
	}
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}

void insertlast(int x)
{
	struct node *newnode= getnewnode(x);
	if(head==NULL)
	{
		head=newnode;
		return ;
	}
	
	struct node *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next=NULL;
}

void print()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void reverseprint()
{
	struct node *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	printf("reverse\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}

int main()
{
	insertathead(3);
	insertathead(4);
	insertlast(10);
	insertathead(1);
	print();
	reverseprint();
	
	return 0;
}
