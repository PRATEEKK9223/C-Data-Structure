#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node* next;
    }*head=NULL,*newnode;

void creat(void);
void display(struct node *HEAD);
struct node* reverse(struct node *HEAD);

void main()
{
    struct node *REVERS_LL;
    creat();
    printf("BEFORE:reverse linked list::\n");
    display(head);
    printf("\nAfter revers the Linked list:::\n");
    REVERS_LL=reverse(head);
    display(REVERS_LL);
   
}

void creat()
{
    int n,i;
    printf("enter the number of nodes you want\n");
    scanf("%d",&n);
    while(i<n)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter te data\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else{
            newnode->next=head;
            head=newnode;
        } 
        i++;  
    }
    
}

void display(struct node *HEAD)
{
    struct node* temp;
    if(HEAD==NULL)
        printf("empty LL\n");
    else{
        temp=HEAD;
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}

struct node* reverse(struct node* HEAD)
{
    struct node *privious,*current,*nextnode;
    privious=NULL;
    current=nextnode=HEAD;
    while(nextnode!=0)
    {
        nextnode= current->next;
        current->next=privious;
        privious=current;
        current=nextnode;
    }
    HEAD=privious;
    return HEAD;
}




