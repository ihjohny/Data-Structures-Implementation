//Reverse print a linked list iterative method
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;

void reverse()
{
	struct node *current,*prev,*next;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
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

void insert(int n)
{
	struct node *temp=new node();
	temp->data=n;
	temp->next=head;
	head=temp;
}

void positioninsert(int data,int n)
{
	struct node *temp1=new node();
	temp1->data=data;
	temp1->next=NULL;
	if(n==1)
	{
		temp1->next=head;
		head=temp1;
		return ;
	}
	else
	{
		struct node *temp2=new node();
		temp2=head;
		for(int i=0;i<n-2;i++)
		{
			temp2=temp2->next;
		}
		temp1->next=temp2->next;
		temp2->next=temp1;
	}
}

int main()
{
	
	head=NULL;
	insert(2);
	insert(8);
	positioninsert(12,2);
	insert(14);
	print();
	printf("\n");
	reverse();
	print();
	
	return 0;
}
