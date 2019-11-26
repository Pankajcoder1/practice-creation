/*implimentation of avl tree*/
#include<stdio.h>
#include<stdlib.h>
int max(int a,int b);
struct node* newnode(int data);
struct node* right_rotation(struct node *root);
struct node* left_rotation(struct node *root);
void inorder(struct node *root);
int get_balance_factor(struct node *root);
struct node *insert(struct node *root, int key);
int height(struct node *root);
struct node *search(struct node *root, int data);

struct node
{
	int data;
	struct node *right;
	struct node *left;
	int height;
};

int max(int a,int b)
{
	return (a > b)? a : b;
}

struct node* newnode(int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->right=NULL;
	temp->left=NULL;
	temp->height=1;
	return temp;
}

struct node* right_rotation(struct node *root)
{
	struct node *temp=NULL;
	temp=root->right;
	root->right=temp->left;
	temp->left=root;
	root->height= 1+max(height(root->right),height(root->left));
	temp->height= 1+max(height(temp->right),height(temp->left));
	return temp;
}

struct node *left_rotation(struct node *root)
{
	struct node *temp=NULL;
	temp=root->left;
	root->left=temp->right;
	temp->right=root;
	root->height= 1+max(height(root->right),height(root->left));
	temp->height= 1+max(height(temp->right),height(temp->left));
	return temp;
}

int height(struct node *root)
{
	if(root==NULL)
		return 0;
	else
		return root->height;
}

struct node *search(struct node *root, int data)
{
	if(root==NULL)
		return 0;
	else if(root->data > data)
		return search(root->left,data);
	else if( root->data < data)
		return search(root->right,data);
	return root;
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	}
}

int get_balance_factor(struct node *root)
{
	if(root==NULL)
		return 0;
	return (height(root->left)-height(root->right));
}

struct node *insert(struct node *root,int key)
{
	if(root==NULL)
		return (newnode(key));
	else if(key > root->data)
		root->right=insert(root->right,key);
	else if(key < root->data)
		root->left=insert(root->left,key);
	else
		return root;
	//height increment
	root->height=1+max(height(root->left),height(root->right));
	int balance_factor=get_balance_factor(root);
	//now rotation
	//l-l rotation
	if(balance_factor > 1 && key < root->left->data)
		return left_rotation(root);
	//r-r rotation
	if(balance_factor < -1 && key > root->right->data)
		return right_rotation(root);
	//l-r rotation
	if(balance_factor > 1 && key > root->left->data)
	{
		root->left=right_rotation(root->left);
		return left_rotation(root);
	}
	//r-l rotation
	if( balance_factor < -1 && key < root->right->data)
	{
		root->right=left_rotation(root->right);
		return right_rotation(root);
	}
	return root;
}

struct node *get_min_from_right(struct node *root)
{
	/*you can teke max from left also*/
	struct node *temp=root->right;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
}
struct node* delete(struct node *root, int key)
{
	if(root==NULL)
		return 0;
	else if(key > root->data)
		root->right=delete(root->right,key);
	else if(key < root->data)
		root->left=delete(root->left,key);
	else
	{
		if(root->left==NULL)
		{
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			struct node *temp=get_min_from_right(root);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	if(root==NULL)
		return root;

	root->height=1+max(height(root->left),height(root->right));
	int balance_factor=get_balance_factor(root);
	//now rotation
	//l-l rotation
	if(balance_factor > 1 && key < root->left->data)
		return left_rotation(root);
	//r-r rotation
	if(balance_factor < -1 && key > root->right->data)
		return right_rotation(root);
	//l-r rotation
	if(balance_factor > 1 && key > root->left->data)
	{
		root->left=right_rotation(root->left);
		return left_rotation(root);
	}
	//r-l rotation
	if( balance_factor < -1 && key < root->right->data)
	{
		root->right=left_rotation(root->right);
		return right_rotation(root);
	}
	return root;
		
}

int main()
{
	int option,value,no,delete_no;
	struct node *root=NULL;
	printf("press.\n\t1 for isertion.\n\t2.for deletion.\n\t3.insert one element.\n");
	printf("\t4.height of any root\n\t5.balance_factor of any node\n\t6.exit\n");
	scanf("%d",&option);
	while(option!=6)
	{
		switch(option)
		{
			case 1:
			{
				printf("enter no of element\n");
				scanf("%d",&value);
				printf("enter element\n");
				for(int i=0;i<value;i++)
				{
					scanf("%d",&no);
					root=insert(root,no);	
				}
				printf("inorder is\n");
				inorder(root);
				printf("\n");
			} break;
			case 2:
			{
				printf("enter the value that you want to delete.\n");
				scanf("%d",&delete_no);
				root=delete(root,delete_no);
				printf("inorder is\n");
				inorder(root);
				printf("\n");	
			} break;
			case 3:
			{
				printf("enter value\n");
				scanf("%d",&no);
				root=insert(root,no);
				printf("inorder is\n");
				inorder(root);
				printf("\n");
			} break;
			case 4:
			{
				printf("enter the root data\n");
				scanf("%d",&no);
				struct node *temp=search(root,no);
				int height1=height(temp);
				printf("%d\n",height1-1);
			} break;
			case 5:
			{
				printf("enter root data\n");
				scanf("%d",&no);
				struct node *temp=search(root,no);
				int balance_factor=get_balance_factor(temp);
				printf("balance factor is %d\n",balance_factor);
			} break;
			default : printf("enter correct input\n");
		}
		scanf("%d",&option);
	}
	free(root);
	return 0;
}