#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;   
};

struct node *head,*newnode;
void main()
{
    //to creat a linkedlist....
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER THE VALUE YOU WANT TO ADD\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else{
            newnode->next=head;
            head=newnode;
        }
        printf("enter zero to end\n");
        scanf("%d",&choice);

    }
    //to display the linked list.......
    struct node *temp=head;

    while(temp!=0)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}