#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
}*head= NULL,*temp,*newnode;

void main()
{
    int choice;
    do
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;//(*newnode).next=NULL;
        newnode->prev=NULL;//(*newnode).prev=NULL;
        
        if(head==NULL){
            head=newnode;
            temp=newnode;

        }
        else{
           
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode; 
        }
        printf("enter 0 to exit loop\n");
        scanf("%d",&choice);
    }while(choice);
    //to display the doubly linked list

    struct  node *temp1=head;
    if(head==NULL)
        printf("no elemen in LL\n");
    else{
        while(temp1!=NULL)
        {
            printf("%d",temp1->data);
            temp1=temp1->next;
            if(temp1!=NULL)//to eleminate last arrow
                printf("<->");
        }
    }
    

}

