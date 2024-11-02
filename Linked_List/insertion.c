#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head=NULL;

struct node *newnode;

struct node* getNode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}
void insert_At_Beging()
{
     newnode=getNode();
    if(head==NULL)
        head=newnode;
    else{
        newnode->next=head;
        head=newnode;
    }
}

void insert_At_end(void)
{
    newnode=getNode();
    struct node* temp;
    temp=head;
    if(head==NULL)
        temp=head=newnode;
    else{
        while(temp->next!=0)
        {
           temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insert_At_pos()
{
    newnode=getNode();
    struct node* temp=head;
    int pos;
    printf("enter the position you want to add\n");
    scanf("%d",&pos);
    int i=1;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void display(void)
{
    struct node *temp=head;
    if(head==NULL)
        printf("LL is empty");
    else{
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}

void main()
{
    insert_At_Beging();
    insert_At_Beging();
    insert_At_Beging();
    display();
    insert_At_end();
    display();
    insert_At_pos();
    display();
}


