#include<stdio.h>
#include<stdlib.h>

struct node{
    int *data;
    struct node* link;
};

typedef struct node NODE;
NODE *head=NULL,*newnode;
int count=0;

NODE* getNode()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode==NULL)
        printf("\nmemory is not allocated\n");
    else{
        printf("\nenter the data\n");
        scanf("%d",&newnode->data);
        newnode->link=NULL;
    }
    return newnode;
}

void insert_At_Beging(NODE *newnode)
{
    newnode=getNode();//to creat new node
    if(head==NULL)
        head=newnode;
    else{
        newnode->link=head;
        head=newnode;
    }
    count++;
}

void insert_At_end(NODE *newnode)
{
    newnode=getNode();//to creat new node
    NODE *temp;
    temp=head;
    if(head==NULL)
        head=newnode;
    else{
        while(temp->link!=0)
            temp=temp->link;
        temp->link=newnode;
    }
    count++;
}
void insert_At_Pos(NODE *newnode,int pos)
{
    NODE *temp=head;
    if(pos>count)
        printf("\ninvalid position\n");
    else
    {
        newnode=getNode();//to creat new node
        if(pos==1)
            insert_At_Beging(newnode);
        else{
            int i=1;
            while(i<pos-1)
            {
                temp=temp->link;
                i++;
            }
            newnode->link=temp->link;
            temp->link=newnode;
        }
         count++;   
    }  
}

void delet_At_Beging()
{
    NODE* temp=head;
    if(head==NULL)
        printf("\nempty linked list\n");
    else{
        head=temp->link;//head->link;
        free(temp);
        count--;
    }
}

void delet_At_end()
{
    NODE *temp=head,*privious;
    if(head==NULL)
        printf("\nempty linked list\n");
    else{
        while(temp->link!=0)
        {
            privious=temp;
            temp=temp->link;
        }
        /*while(temp->link->link!=0)
        {
            temp=temp->link;
        }
        privious=temp->link;*/
        privious->link=0;
        free(temp);
        count--;
    }
}

void delet_At_pos(int pos)
{
    NODE *temp=head,*next;
    if(pos>count)
        printf("\ninvalid position\n");
    else{
        int i=1;
        while(i<pos-1)
        {
            temp=temp->link;
            i++;
        }
        next=temp->link;
        temp->link=next->link;
        free(next);
        count--;
    }
}

void display()
{
    NODE *temp=head;
    if(head==NULL)
        printf("\nempty linked list\n");
    else{
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("\nthe number of NODES in liked list is %d\n",count);
    }
}

void main()
{
    int choice,pos;
    while(1)
    {
        printf("\nenter your chioce\n 1:creat node\n 2:insert at front\n 3:insert at end \n 4:insert at position\n 5:delet at front\n 6:delet at end\n 7:delet at postion\n 8:display\n 9: exit...\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                newnode=getNode();
                break;
            case 2:
                insert_At_Beging(newnode);
                break;
            case 3:
                insert_At_end(newnode);
                break;
            case 4:
                printf("enter te position to insert\n");
                scanf("%d",&pos);
                insert_At_Pos(newnode,pos);
                break;
            case 5:
                delet_At_Beging();
                break;
            case 6:
                delet_At_end();
                break;
            case 7:
                printf("enter the position you want to delet\n");
                scanf("%d",&pos);
                delet_At_pos(pos);
                break;
            case 8:
                printf("linked list element are\n");
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("invalid postion\n");
        }
    }
}
