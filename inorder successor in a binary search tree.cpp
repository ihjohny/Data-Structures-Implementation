//inorder successor in a binary search tree
#include<iostream>
using namespace std;
struct bstnode 
{
	int data;
	bstnode *left;
	bstnode *right;
};

bstnode* find(bstnode *root,int data)
{
	if(root->data==data)
	{
		return root;
	}
	else if(data<root->data) return find(root->left,data);
	else if(data>root->data) return find(root->right,data);
}

bstnode* getinordersuccessor(bstnode *root,int data)
{
	bstnode *current=find(root,data);
	if(current==NULL) return NULL;
	
	if(current->right!=NULL)
	{
		bstnode* temp=current->right;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		return temp;
	}
	else
	{
		bstnode *successor=NULL;
		bstnode *ancestor=root;
		while(ancestor!=current)
		{
			if(current->data<ancestor->data)
			{
				successor=ancestor;
				ancestor=ancestor->left;
			}
			else
			{
				ancestor=ancestor->right;
			}
		}
		return successor;
	}
}

int main()
{
	
	return 0;
}
