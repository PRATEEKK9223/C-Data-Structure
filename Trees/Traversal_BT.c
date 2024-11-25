// Traversing of binary tree in inorder,preorder,postorder 

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild,*rchild;
};

struct node* creat()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data(-1 for end)\n");
    scanf("%d",&x);
    newnode->data=x;
    if(x==-1)
        return 0;
    else{
        printf("enter the leftchild of node %d\n",x);
        newnode->lchild=creat();
        printf("enter the right child of the node %d\n",x);
        newnode->rchild=creat();
    }
    return newnode;
}

void Inorder_traversing(struct node *root)
{
    if(root==0)
        return;
    else{
        Inorder_traversing(root->lchild);
        printf("%d ",root->data);
        Inorder_traversing(root->rchild);
    }
}

void preorder_trversing(struct node *root)
{
    if(root==0)
        return ;
    else{
        printf("%d ",root->data);
        preorder_trversing(root->lchild);
        preorder_trversing(root->rchild);
    }
}

void postorder_traversing(struct node *root)
{
    if(root==0)
        return;
    else{
        postorder_traversing(root->lchild);
        postorder_traversing(root->rchild);
        printf("%d ",root->data);
    }
}

void main()
{
    struct node *root=0;
    printf("creating of binary tree\n");
    root=creat();
    printf("\ninorder traversal of binar tree\n");
    Inorder_traversing(root);

    printf("\npreorder traversal of binar tree\n");
    preorder_trversing(root);

    printf("\npostorder traversal of binar tree\n");
    postorder_traversing(root);
}