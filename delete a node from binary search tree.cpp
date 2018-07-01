//Delete a node from binary search tree
#include<iostream>
using namespace std;
struct bstnode
{
	int data;
	bstnode *left;
	bstnode *right;
};


bstnode* findmin(bstnode *root)
{
	//if(root==NULL) return -1;
	
	if(root->left==NULL)
	{
		return root;
	}
	findmin(root->left);
}
bstnode* deletenode(bstnode* root,int data)
{
	if(root==NULL) return NULL;
	else if(data<root->data) root->left=deletenode(root->left,data);
	else if (data>root->data) root->right=deletenode(root->right,data);
	else if(data==root->data)
	{
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		else if(root->left==NULL)
		{
			bstnode *temp = root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			bstnode *temp=root;
			root=root->left;
			delete temp;
		}
		else
		{
			bstnode *temp=findmin(root->right);
			root->data=temp->data;
			root->right=deletenode(root->right,temp->data);
		}
	}
	return root;
}

int main()
{
	return 0;
}
