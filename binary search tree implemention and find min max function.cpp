//binary search tree implementation in c++
#include<iostream>
#include<cstdlib>
using namespace std;
struct bstnode
{
	int data;
	bstnode *left;
	bstnode *right;
};
bstnode *getnewnode(int data)
{
	bstnode *newnode=(bstnode*)malloc(sizeof(bstnode));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

bstnode* insert(bstnode *root,int data)
{
	if(root==NULL)
	{
		root=getnewnode(data);
		return root;
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

bool search(bstnode *root,int data)
{
	if(root==NULL) return false;
	else if(root->data==data)return true;
	else if(data<=root->data) return search(root->left,data);
	else return search(root->right,data);
}
/*
int findmin(bstnode *root)
{
	if(root==NULL)
	{
		cout<<"Error : tree is empty"<<endl;
		return -1;
	}
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root->data;
}

int findmax(bstnode *root)
{
	if(root==NULL)
	{
		cout<<"Eror : tree is empty"<<endl;
		return -1;
	}
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root->data;
}
*/
//*recursinve 
int findmin(bstnode *root)
{
	if(root==NULL)
	{
		cout<<"error"<<endl;
		return -1;
	}
	else if(root->left==NULL)
	{
		return root->data;
	}
	return findmin(root->left);
}


int findmax(bstnode *root)
{
	if(root==NULL)
	{
		cout<<"error"<<endl;
		return -1;
	}
	else if(root->right==NULL)
	{
		return root->data;
	}
	return findmin(root->right);
}
//*/
int main()
{
	bstnode *root=NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	
	if(search(root,18))
	{
		cout<<"fount number"<<endl;
	}
	else 
	{
		cout<<"not found"<<endl;
	}
	cout<<"findmin = "<<findmin(root)<<endl;
	cout<<"findmax = "<<findmax(root)<<endl;
	return  0;
}
