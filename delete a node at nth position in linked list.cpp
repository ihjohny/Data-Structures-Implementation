//delete a node at nth position
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head; 
void insert (int x)
{
	node *temp=(node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
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

void Delete(int n)
{
	struct node *temp1=head;
	if(n==1)
	{
		head=temp1->next;
		free(temp1);
		return ;
	}
	for(int i=0;i<n-2;i++)
	{
		temp1=temp1->next;
	}
	struct node *temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);
}

int main()
{
	head=NULL;
	printf("how many number\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the number\n");
		scanf("%d",&x);
		insert(x);
		print();
	}
	int d;
	printf("Enter deleted element\n");
	scanf("%d",&d);
	Delete(d);
	print();
	
	return 0;
}
