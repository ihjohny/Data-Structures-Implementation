//Reverse a linked list using recursion
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};

struct node *head;
struct node* insert(int n)
{
	struct node *temp=new node();
	temp->data=n;
	temp->next=head;
	head=temp;
	;
}

void recursionprint(struct node *p)
{
	
	if(p->next==NULL)
	{
		head=p;
		return;		
	}
	recursionprint(p->next);
	struct node *q=new node();
	q=p->next;
	q->next=p;
	p->next=NULL;
}

void print()
{
	struct node *temp=head;
	printf("List is: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	recursionprint(head);
	print();
	
	return 0;
}
