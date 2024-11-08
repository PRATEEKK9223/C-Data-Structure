#include<stdio.h>
#include<stdlib.h>

void main()
{
    struct node{
        char ele;
        struct node *next;
    }*head=NULL,*newnode;

    typedef struct node CLL;
    CLL *tail=NULL;

    int n;
    
    printf("enter the number of nodes you want to add\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode=(CLL*)malloc(sizeof(CLL));
        printf("enter the character\n");
        getchar(); //it to clear the newline character left by the previous sacnf function
        scanf("%c",&newnode->ele);
        newnode->next=NULL;

        if(newnode==0)
            printf("memory is not allocated\n");
        else if(head==0)
        {
            tail=head=newnode;
            tail->next=head;
        }
        else{
            tail->next=newnode;
            newnode->next=head;
            tail=newnode;
        }

    }
    getchar();


    //to display the circuler linked list
    CLL *temp=head;
    if(head==NULL)
        printf("empty ll\n");
    else{
        do{
        printf("%c",temp->ele);
        temp=temp->next;
        if(temp!=head)
            printf("->");
    }while(temp!=head);
    }

}