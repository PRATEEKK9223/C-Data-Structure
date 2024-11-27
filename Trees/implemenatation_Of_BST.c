#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild,*rchild;
};

typedef struct node TreeNode;


TreeNode* getNode(int data)
{
    TreeNode *newnode;
    newnode=(TreeNode*)malloc(sizeof(TreeNode));
    newnode->data=data;
    newnode->lchild=0;
    newnode->rchild=0;
    return newnode;
}

TreeNode* insert(TreeNode* root,int data)
{
    if(root==NULL)
        root=getNode(data);
    else if(data < root->data)
        root->lchild=insert(root->lchild,data);
    else
        root->rchild=insert(root->rchild,data);
    return root;
}

void Inorder(TreeNode *root)
{
    if(root==0)
        return;
    else{
        Inorder(root->lchild);
        printf("%d-",root->data);
        Inorder(root->rchild);
    }
}

void main()
{
    TreeNode *root=0;
    int num,data;
    printf("eneter the nuber of nodes you want to creat BST\n");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        printf("enter the data >>\n");
        scanf("%d",&data);
        root=insert(root,data);
    }
    Inorder(root);
}