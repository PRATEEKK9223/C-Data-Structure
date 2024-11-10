#include<stdio.h>
#include<stdlib.h>


struct node{
    char ch;
    struct node *prev,*next;
}*head=0,*tail;
void main()
{
    struct node *newnode;
    int n,i=0;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    while(i<n)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        getchar();
        scanf("%c",&newnode->ch);

        if(head==NULL)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        i++;
    }

    // for display the nodes
    struct node *temp=head;
    if(head==NULL)
        printf("empty\n");
    else{
        do{
            printf("%c",temp->ch);
            temp=temp->next;
            if(temp!=tail->next)
                printf("<->");
        }while(temp!=tail->next);

    }
}