//find height of a binary tree
#include<iostream>
using namespace std;
struct bst
{
	int data;
	struct bst *left;
	struct bst *right; 
};

bst* getnewnode(int x)
{
	struct bst *temp=new bst();
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

bst* insert(bst *root,int data)
{
	if(root==NULL)
	{
		struct bst *temp=getnewnode(data);
		root=temp;
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

int max(int x,int y)
{
	if(x>y)
		return x;
	else return y;
}
int findhight(bst *root)
{
	if(root==NULL)
	{
		return -1;
	}
	return max(findhight(root->left),findhight(root->right))+1;
}
int main()
{
	struct bst *root=NULL;
	root=insert(root,22);
	root=insert(root,33);
	root=insert(root,12);
	root=insert(root,10);
	
	cout<<findhight(root);
	
	return 0;
}
