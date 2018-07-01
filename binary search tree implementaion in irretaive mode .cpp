//binary search tree implementaion irretative method 
#include<iostream>
using namespace std;

struct tree
{
	int number;
	struct tree *leftchild;
	struct tree *rightchild;
};
struct tree *root=NULL;

void insert(int x)
{
	tree *temp=new tree();
	tree *current=NULL,*parent=NULL;
	temp->number=x;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		current=root;
		parent=NULL;
		while(1)
		{
			parent=current;
			if(x<=parent->number)
			{
				current=current->leftchild;
				if(current==NULL)
				{
					parent->leftchild=temp;
					return ;
				}
			}
			else
			{
				current=current->rightchild;
				if(current==NULL)
				{
					parent->rightchild=temp;
					return ;
				}
			}			
		}
	
	}
}

void search(int value)
{
	tree *current=root;
	int flag=0;
	while(1)
	{
		if(value==current->number)
		{
			flag=1;
			break;
		}
		else if(value<=current->number)
		{
			current=current->leftchild;
		}
		else 
		{
			current=current->rightchild;
		}
		if(current==NULL)
		{
			break;
		}
	}
	if(flag==1)
	{
		cout<<value<<" Found on the tree"<<endl;
	}
	else
	{
		cout<<"Not found on the tree"<<endl;
	}
}


int main()
{
	insert(10);
	insert(15);
	insert(20);
	insert(25);
	insert(30);
	search(25);
	return 0;
}
