//print linked list using recursion
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};

struct node* insert(node *head,int n)
{
	struct node *temp=new node();
	temp->data=n;
	temp->next=head;
	head=temp;
	return head;
}

void print(struct node *p)
{
	
	if(p==NULL) return;		
	printf("%d ",p->data);
	print(p->next);

}
int main()
{
	struct node *head;

	head=insert(head,1);
	head=insert(head,2);
	head=insert(head,3);
	head=insert(head,4);
	head=insert(head,5);
	print(head);
	
	return 0;
}
