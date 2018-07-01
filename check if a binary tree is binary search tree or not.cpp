//check if a binary tree is binary search tree or not
#include<iostream>
using namespace std;

int  int_MIN = -999999;
int  int_MAX = 999999;

struct bstnode
{
	int data;
	bstnode *left;
	bstnode *right;
};

/*
//check if a binary tree is binary search tree or not

bool issubtreelesser(bstnode *root,int data)
{
	if(root==NULL)return true;
	if(
	root->data<=data && 
	issubtreelesser(root->left,data)&&
	issubtreelesser(root->right,data)
	)
	{
		return true;
	}
	else return false;
}

bool issubtreegreater(bstnode *root,int data)
{
	if(root==NULL)return true;
	if (
	root->data>data&&
	issubtreegreater(root->left,data)&&
	issubtreegreater(root->right,data)
	)
	{
		return true;
	}
	else return false;
}


bool isbinarysearchtree(bstnode *root)
{
	if(root==NULL)return true;
	if( 
	issubtreelesser(root->left,root->data) &&
	issubtreegreater(root->right,root->data) &&
	isbinarysearchtree(root->left) && isbinarysearchtree(root->right)
	)
	{
		return true;
	}
	else return false;
}

/*

//using find max and min process for checking
int findmin(bstnode *root)
{
	if(root==NULL) return -1;
	if(root->left==NULL)
	{
		return root->data;
	}
	return findmin(root->left);
}

int findmax(bstnode *root)
{
	if(root==NULL) return -1;
	if(root->right==NULL)
	{
		return root->data;
	}
	return findmax(root->right);
}

bool isbinarysearchtree_usingmaxmin(bstnode *root)
{
	if(root==NULL)return true;
	if(
	(root->left==NULL||findmax(root->left)<=root->data)&&
	(root->right==NULL||(findmin(root->right)>root->data))&&
	isbinarysearchtree_usingmaxmin(root->left)&&
	isbinarysearchtree_usingmaxmin(root->right)
	)
	{
		return true;
	}
	else return false;
}

*/
bool isbstutil(bstnode *root,int minvalue,int maxvalue)
{
	if(root==NULL)return true;
	if(root->data>minvalue && root->data<maxvalue
	   && isbstutil(root->left,minvalue,root->data)
	   && isbstutil(root->right,root->data,maxvalue)
		)
	{
		return true;
	}
		else return false;
}

bool isbinarysearchtree(bstnode *root)
{
	return isbstutil(root, int_MIN,int_MAX);
}


//


int main()
{
	
	return 0;
}
