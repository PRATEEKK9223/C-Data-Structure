#include<stdio.h>
#include<stdlib.h>

struct node{
    int data; 
    struct node *next; 
};

struct node *front=0;
struct node *rare=0;
struct node *newnode;

struct node* getNode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==0)
        printf("memory not alloctaed\n");
    printf("enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    return newnode;
}

// when implementing the queue using LL that must follows two principles
// 1: It follows FIFO printciple
// 2: it takes O(1) time complexity
// to maintain O(1)time complexity we maintain two pointers

void enQueue()
{
    newnode=getNode();
    if(rare==0 && front==0)
        rare=front=newnode;
    else{
        rare->next=newnode;
        rare=newnode;
    }
}
void deQueue()
{
    struct node *temp=front;
    if(rare==0 && front==0)
        printf("Queue is empty\n");
    else{
        front=front->next;
        free(temp);
    }
}
void display()
{
    struct node *temp=front;
    if(rare==0 && front==0)
        printf("Queue is empty\n");
    else{
        while(temp!=0)
        {
            printf("%d",temp->data);
            temp=temp->next;
            if(temp!=0)
                printf("->");
        }
        printf("\n");
    }
}


void main()
{
    int choice,ele;
    for(;;)
    {
        printf("enter your choice\n");
        printf("1-insertion: 2-deletion: 3-display: 4-exit>>>>>>>\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice\n");

        }
    }
}
