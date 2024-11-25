#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *leftchild,*rightchild;
};

struct node* creat()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data(enter -1 to stop)\n");
    scanf("%d",&x);
    newnode->data=x;
    if(x==-1)
        return 0;
    else{
        printf("enter the leftchild of node %d\n",x);
        newnode->leftchild=creat();
        printf("enter te rightcild of the node %d\n",x);
        newnode->rightchild=creat();
        return newnode;
    }
}

void main(void)
{
    struct node *root=0;
    root=creat();
}