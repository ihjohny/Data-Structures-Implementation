//Binary tree
#include<iostream>
#include<cstdlib>
#include<queue> //for level order traversal
using namespace std;
int  int_MIN = -999999;
int  int_MAX = 999999;

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
	if(root->left==NULL)
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
	if(root->right==NULL)
	{
		return root->data;
	}
	return findmax(root->right);
}


int max(int x,int y)
{
	if(x>y)
		return x;
	else return y;
}
int findhight(bstnode *root)
{
	if(root==NULL)
	{
		return -1;
	}
	return max(findhight(root->left),findhight(root->right))+1;
}

void levelorder(bstnode *root)
{
	if(root==NULL)return ;
	queue<bstnode*>q;
	q.push(root);
	while(!q.empty())
	{
		bstnode *current=q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL)q.push(current->left);
		if(current->right!=NULL)q.push(current->right);
		q.pop();
	}
}

///inorder ,preorder, postorder tree traversal
void preorder(bstnode *root)
{
	if(root==NULL)return;
	cout<<" "<<root->data;
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
//*/

//
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
*/
/*
//using find max and min process for checking
int findmin(bstnode *root)
{
	if(root==NULL) return -1;
	if(root->left==NULL)
	{
	//	cout<<"root data min"<<root->data<<endl;
		return root->data;
	}
	return findmin(root->left);
}
int findmax(bstnode *root)
{
	if(root==NULL) return -1;
	if(root->right==NULL)
	{
	//	cout<<"root data max"<<root->data<<endl;
		return root->data;
	}
	return findmax(root->right);
}
*/
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

//

/*
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
*/
//check is binary tree using inorder traversal
bool check_inorder_traversal(bstnode *root,int temp)
{
	if(root==NULL) return true ;
	
	check_inorder_traversal(root->left,temp);
	
	//cout<<root->data<<" ";
	if(root->data<temp) return false;
	temp=root->data;
	
	check_inorder_traversal(root->right,temp);
}


//

//delete a node form binary search tree
bstnode* findminm(bstnode *root)
{
	//if(root==NULL) return -1;
	
	if(root->left==NULL)
	{
		return root;
	}
	findminm(root->left);
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
			bstnode *temp=findminm(root->right);
			root->data=temp->data;
			root->right=deletenode(root->right,temp->data);
		}
	}
	return root;
}
//

//Inorder ancesstor of a binary search tree

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
//
///

int main()
{
	bstnode *root=NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);

	root=insert(root,8);
	root=insert(root,-12);
	root=insert(root,0);
	root=insert(root,909);
			root=insert(root,-77);

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

	cout<<"hight of the tree :"<<findhight(root)<<endl;

	cout<<"lever order traversal"<<endl;
	levelorder(root);

	cout<<"\npreorder  inorder  postorder tree traversal"<<endl;
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
/*	
	cout<<"is binary serach tree "<<endl;
	if(isbinarysearchtree(root))
	{
		cout<<"Binary search tree"<<endl;
	}
	else
	{
		cout<<"Not a binary search tree"<<endl;
	}
*/	
///*
	cout<<"is binary tree using max min process"<<endl;
	
	if(isbinarysearchtree_usingmaxmin(root))
	{
		cout<<"Binary search tree"<<endl;
	}
	else
	{
		cout<<"Not a binary search tree"<<endl;
	}
//*/	
	
	cout<<"check in order traversla provess "<<endl;
	if(check_inorder_traversal(root,-999))
	{
		cout<<"Binary search tree"<<endl;
	}
	else
	{
		cout<<"Not a binary search tree"<<endl;
	}
	
	//
	cout<<"delete a node form binary tree"<<endl;
	int a;
	cin>>a;
	deletenode(root,a);
	inorder(root);
	cout<<endl;
	//
	
	cout<<"get inorder successor"<<endl;
	cout<<"input for successor"<<endl;
	int b;
	cin>>b;
	cout<<getinordersuccessor(root,b)->data<<endl;
	
	
	return  0;
}
