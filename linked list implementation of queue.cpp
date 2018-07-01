//linked list implementation of queue
#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x)
{
	node *temp = new node();
	temp->data=x;
	temp->next=NULL;
	if(front==NULL&&rear==NULL)
	{
		front=rear=temp;
		return ;
	}
	rear->next=temp;
	rear=temp;
}

void dequeue()
{
	struct node *temp=front;
	if(front==NULL) return ;
	if(front==rear)
	{
		front=rear=NULL;
	}
	else
	{
		front=front->next;
	}
//	free(temp);
}

int qfront()
{
	return front->data;
}
int qrear()
{
	return rear->data;
}

int main()
{
	enqueue(2);
	enqueue(4);
	enqueue(1);
	enqueue(11);
	dequeue();
	cout<<"front "<<qfront()<<endl;
	cout<<"rear "<<qrear()<<endl;
	return 0;
}
