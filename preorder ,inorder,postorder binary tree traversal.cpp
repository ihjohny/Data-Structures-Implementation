///preorder,inorder and postorder Binary tree traversal
#include<iostream>
using namespace std;
struct bstnode {
	int data;
	node *left;
	node *right;
};
void preorder(bstnode *root)
{
	if(root==NULL)return;
	cout<<" "<<root->data<<;
	preorder(root->left);
	preorder(root->right);
}

 void inorder(bstnode *root)
 {
	if(root==NULL)return ;
	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);
 }

 void postorder(bstnode *root)
 {
	if(root==NULL) return ;
	postorder(root->left);
	postorder(root->right);
	cout<<" "<<root->data;
 }
int main()
{

	return 0;
}
