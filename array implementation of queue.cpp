///array implementation of queue
#include<iostream>
using namespace std;
int a[10];
int qfront =-1;
int qrear=-1;
bool is_empty()
{
	if(qfront==-1&&qrear==-1)
	return true;
	else
	return false;
}

bool is_full()
{
	if(qrear==10-1)
	return true;
	else return false;
}
int front()
{
	return a[qfront];
}
int rear()
{
	return a[qrear];
}

void enqueue(int x)
{
	if(is_full()||(qrear+1)%10==qfront)
	{
		return ;
	}
	else  if(is_empty())
	{
		qfront=0;
		qrear=0;
	}
	else
	{
		qrear=(qrear+1)%10;
	}
		a[qrear]=x;
}

void dequeue()
{
	if(is_empty())
	return;
	else if(qfront==qrear)
	{
		qfront=-1;
		qrear=-1;
	}
	else
	{
		qfront=(qfront+1)%10;
	}
}

 int main()
 {
	enqueue(111);
	enqueue(12);
	enqueue(14);
	enqueue(15);
	enqueue(9);
	cout<<"front "<<a[qfront]<<"\nrear "<<a[qrear]<<endl;
	dequeue();
	cout<<"front "<<a[qfront]<<"\nrear "<<a[qrear]<<endl;
	return 0;
 }
