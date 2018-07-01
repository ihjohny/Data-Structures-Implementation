// reverse a linked list using stack
#include<iostream>
#include<stack>
using namespace std;
struct node 
{
	int data;
	node *next;
};
struct node *head;

void insertathead(int n)
{
	node *temp=new node();
	temp->data=n;
	temp->next=head;
	head=temp;
}


void print()
{
	node *temp=new node();
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	cout<<endl;
}

void reverse()
{
	stack<struct node*>s;
	node *temp=head;
	while(temp!=NULL)
	{
		s.push(temp);
		temp=temp->next;
	}
	temp=s.top();
	head=temp;
	s.pop();
	while(!s.empty())
	{
		temp->next=s.top();
		s.pop();
		temp=temp->next;
	}
	temp->next=NULL;
}

int main()
{
	head=NULL;	
	insertathead(2);
	insertathead(4);
	insertathead(10);
	insertathead(1);
		print();
	reverse();
		print();
	
	return 0;
}
