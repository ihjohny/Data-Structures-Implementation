//check is binary tree using inorder traversal
#include<iostream>
using namespace std;
struct bstnode
{
	int data;
	bstnode *left;
	bstnode *right;
};

bool check_inorder_traversal(bstnode *root,int temp)
{
	if(root==NULL) return true ;
	
	check_inorder_traversal(root->left,temp);
	
	//cout<<root->data<<" ";
	if(root->data<temp) return false;
	temp=root->data;
	
	check_inorder_traversal(root->right,temp);
}

int main()
{
	
	return 0;
}
